#!/usr/bin/env bash
# Setting up client config file

file { '/etc/ssh/ssh_config':
  ensure => present,
}

file_line { 'Turn off passwd auth':
  patth   => '/etc/ssh/ssh_config',
  line    => '    PasswordAuthentication no',
  match   => '#PasswordAuthentication',
}

file_line { 'Delare identity file':
  path    => '/etc/ssh/ssh_config',
  line    => '    IdentityFile ~/.ssh/school',
  match => '#IdentityFiile',
}
