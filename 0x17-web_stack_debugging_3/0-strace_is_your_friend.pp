# A manifest to fix Apache configuration
exec { 'fix config file':
  command => "sed -i 's/phpp/php/g' /var/www/html/wp-settings.php",
  path    => '/bin'
}
