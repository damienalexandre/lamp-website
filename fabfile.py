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

def exportDB():
    print(green('Starting DB export with drush'))
    now = datetime.datetime.now()
    fileName = 'lamp-'+str(now.year)+'-'+str(now.month)+'-'+str(now.day)+'-'+str(now.hour)+':'+str(now.minute)+'.sql'

    local('drush watchdog-delete all')
    local('drush sql-dump --result-file=/tmp/'+fileName)

    print(green('Compressing local files'))
    local('tar -czvf /tmp/lamp-sql.tar.gz /tmp/'+fileName)

    print(red('Uploading archive'))
    put('/tmp/lamp-sql.tar.gz /tmp/lamp-sql.tar.gz')

    print(green('Uncompress on distant'))
    run('tar -C /tmp -xzvf /tmp/lamp-sql.tar.gz')

    sqlString = 'mysql --database=lamp --host=localhost --user=root --password=poney'
    print(red('Starting remote mysql import'))
    run( sqlString + ' < /tmp/' + fileName)

    print(green('Cleanup!'))
    local('rm /tmp/' + fileName)
    local('rm /tmp/lamp-sql.tar.gz')
    run('rm /tmp/' + fileName)
    run('rm /tmp/lamp-sql.tar.gz')


@task(default=True)
def deploy():
    exportFiles()
    exportDB()