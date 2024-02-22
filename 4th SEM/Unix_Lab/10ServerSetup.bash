# Update and Install Apache
sudo apt update
sudo apt install -y apache2

# Allow Apache through Firewall
sudo ufw allow in "Apache"
sudo ufw allow ssh
sudo ufw app list

# Install MySQL
sudo apt install -y mysql mysql-server
sudo mysql -u root -p

# Install PHP and Related Packages
sudo apt install -y php libapache2-mod-php php-mysql php-sqlite3

# Restart Apache
sudo service apache2 restart

# Create and Edit info.php
echo "<?php phpinfo(); ?>" | sudo tee /var/www/html/info.php

# Check PHP Installation
# Open a web browser and visit either 'localhost/info.php' or '127.0.0.1/info.php'
