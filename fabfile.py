from fabric.api import *
from fabric.colors import green, red
import datetime

env.hosts = ['188.165.241.139']
env.user  = 'root'

@task
def exportFiles():
    print(green('Compressing local files'))
    local('tar -czvf /tmp/lamp.tar.gz --exclude .git --exclude "*.log" --exclude "sites/*/settings*.php" .')
    print(red('Uploading archive'))
    put('/tmp/lamp.tar.gz', '/tmp/lamp.tar.gz')

    print(green('Uncompress on distant'))
    with cd('/tmp'):
        drupalDirectory = '/var/www/lamp/'
        run('tar -C ' + drupalDirectory + ' -xzvf lamp.tar.gz')

        print(green('Cleanup!'))
        local('rm /tmp/lamp.tar.gz')
        run('rm /tmp/lamp.tar.gz')

    with cd(drupalDirectory):
        run('cp sites/default/default.settings.php sites/default/settings.php');

@task
def exportDB():
    print(green('Starting DB export with drush'))
    now = datetime.datetime.now()
    fileName = 'lamp-'+str(now.year)+'-'+str(now.month)+'-'+str(now.day)+'-'+str(now.hour)+':'+str(now.minute)+'.sql'

    local('drush watchdog-delete all')
    local('drush sql-dump --result-file=/tmp/'+fileName)

    print(green('Compressing local files'))
    local('tar -czvf /tmp/lamp-sql.tar.gz /tmp/'+fileName)

    print(red('Uploading archive'))
    put('/tmp/lamp-sql.tar.gz',  '/tmp/lamp-sql.tar.gz')

    print(green('Uncompress on distant'))

    sqlString = 'mysql --database=lamp --host=localhost --user=root --password=poney'
    print(red('Starting remote mysql import'))

    run('mysqladmin -uroot -pponey create lamp')
    run('tar -Oxzvf /tmp/lamp-sql.tar.gz | ' + sqlString)

    print(green('Cleanup!'))
    local('rm /tmp/' + fileName)
    local('rm /tmp/lamp-sql.tar.gz')
    run('rm /tmp/lamp-sql.tar.gz')

@task
def getStats():
    with cd('/tmp'):
        print(green('Get access log summary'))
        put('./logparse',  '/var/www/lamp/logparse')
        run('chmod +x /var/www/lamp/logparse')
        run('/var/www/lamp/logparse -f /var/log/apache2/other_vhosts_access.log -h http://dist.lamp.fr/')
        get('/tmp/urls.txt',  './urls.txt')

@task(default=True)
def deploy():
    exportFiles()
    exportDB()