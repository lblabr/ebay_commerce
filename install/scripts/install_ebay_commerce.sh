#!/bin/bash

# Make sure we run as root.
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root!"
   exit 1
fi
 
# Get domain name.
read -p "
Website domain name : "
if [[ -n $REPLY ]]
then
  WEBSITE_URL=$REPLY
else
 exit 1
  echo "Must enter domain name"
fi

echo ">>>> Create the directory."
mkdir -p /var/www/$WEBSITE_URL/public_html
echo ">>>> Grant Permissions."
chown -R $USER:$USER /var/www/$WEBSITE_URL/public_html
echo ">>>> Create index.html"
echo "<html><head><title>www.example.com</title></head><body><h1>Success: You Have Set Up a Virtual Host</h1></body></html>" > /var/www/$WEBSITE_URL/public_html/index.html
echo ">>>> Create the Virtual Host File."
echo "
<VirtualHost *:80>
	ServerAdmin webmaster@localhost
    ServerName "$WEBSITE_URL"
    ServerAlias "$WEBSITE_URL"
	DocumentRoot /var/www/"$WEBSITE_URL"/public_html
	DirectoryIndex index.php index.html
	<Directory />
		Options FollowSymLinks
		AllowOverride None
	</Directory>
	<Directory /var/www/>
		Options Indexes FollowSymLinks MultiViews
		AllowOverride None
		Order allow,deny
		allow from all
	</Directory>

	ScriptAlias /cgi-bin/ /usr/lib/cgi-bin/
	<Directory "/usr/lib/cgi-bin">
		AllowOverride None
		Options +ExecCGI -MultiViews +SymLinksIfOwnerMatch
		Order allow,deny
		Allow from all
	</Directory>

	ErrorLog ${APACHE_LOG_DIR}/error.log

	# Possible values include: debug, info, notice, warn, error, crit,
	# alert, emerg.
	LogLevel warn

	CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>
" > /etc/apache2/sites-available/$WEBSITE_URL
echo ">>>> Activate the host with the built-in apache shortcut."
a2ensite $WEBSITE_URL
echo ">>>> Restart Apache."
service apache2 restart


# Get domain name.
read -p "
DRUSH ALIAS : "
if [[ -n $REPLY ]]
then
  DRUSH_ALIAS=$REPLY
else
 exit 1
  echo "Must enter alias"
fi

echo ">>>> Create drush alias $DRUSH_ALIAS."
echo "<?php
\$aliases['$DRUSH_ALIAS'] = array(
  'root' => '~/var/www/$WEBSITE_URL/public_html/',
  'uri' => '$WEBSITE_URL',);" > /etc/drush/$DRUSH_ALIAS.alias.drushrc.php
echo ">>>> Get grumpy config files."
git clone https://edwinknol@bitbucket.org/edwinknol/grumpy.public.git ~/grumpy
cp ~/grumpy/drupal.make /var/www/$WEBSITE_URL/public_html
cd /var/www/$WEBSITE_URL/public_html
drush make -y drupal.make
cd ~

# Ask for the database name to create.
read -p "
Database name to create : "
if [[ -n $REPLY ]]
then
  DATABASE_NAME=$REPLY
else
 exit 1
  echo "Must enter database name"
fi

# Ask for the database user name.
read -p "
Database user name : "
if [[ -n $REPLY ]]
then
  SQL_USER=$REPLY
else
 SQL_USER=$WEBSITE_URL
fi

# Ask for the database pswrd.
read -p "
Database user password : "
if [[ -n $REPLY ]]
then
 SQL_PASSWORD=$REPLY  
else
 SQL_PASSWORD=$(tr -dc "[:alpha:]" < /dev/urandom | head -c 10)
fi

mysql -u root -p
create database $DATABASE_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
grant all on $DATABASE_NAME.* to '$SQL_USER' identified by '$SQL_PASSWORD';
flush privileges;
quit

service apache2 restart