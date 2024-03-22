# Install especific version of flask (2.1.0)

exec {'puppet-lint':
  command => '/usr/bin/sudo apt-get -y install puppet-lint -v 2.1.0',
}
