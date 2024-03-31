# puppet custom http response header
node 'default' {
    class { 'nginx': }

    nginx::resource::server { 'default':
      listen_port => 80,
      server_name => ['localhost'],
      www_root    => '/var/www/html',
      location_cfg_append => {
        'add_header' => 'X-Served-By $hostname',
      },
    }
}
