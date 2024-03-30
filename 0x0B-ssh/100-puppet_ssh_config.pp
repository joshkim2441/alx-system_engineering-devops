#!/usr/bin/env bash
# Setting up client config file
include stdlib
file { '/etc/ssh/ssh_config':
  ensure => present,
}

file_line { 'Turn off passwd auth',
  ensure  => present,
  patth   => '/etc/ssh/ssh_config',
  line    => '    PasswordAuthentication no',
  replace => true
}

file_line { 'Delare identity file'
  ensure  => present,
  path    => '/etc/ssh/ssh_config',
  line    => '    IdentityFile ~/.ssh/school',
  replace => true,
}
