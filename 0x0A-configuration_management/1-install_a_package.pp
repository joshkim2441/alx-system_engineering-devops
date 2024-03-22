# Install especific version of flask (2.1.0)

exec {'install-flask':
  command => '/usr/bin/sudo pip3 install flask==2.1.0',
}
