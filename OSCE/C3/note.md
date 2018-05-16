- Processes

1. use `ps -el` can get the pid and ppid

2. use `pstree` can get the processes create tree like

  ```
  [vagrant@chenwen code-snippets-for-note]$ pstree
  init─┬─VBoxService───7*[{VBoxService}]
       ├─auditd───{auditd}
       ├─console-kit-dae───63*[{console-kit-da}]
       ├─crond
       ├─dbus-daemon
       ├─dhclient
       ├─master─┬─pickup
       │        └─qmgr
       ├─6*[mingetty]
       ├─nginx───4*[nginx]
       ├─redis-server───2*[{redis-server}]
       ├─rpc.statd
       ├─rpcbind
       ├─rsyslogd───3*[{rsyslogd}]
       ├─salt-master─┬─3*[salt-master───2*[{salt-master}]]
       │             └─salt-master─┬─5*[salt-master───18*[{salt-master}]]
       │                           └─salt-master───6*[{salt-master}]
       ├─salt-minion
       ├─sshd─┬─sshd───sshd───bash───pstree
       │      └─sshd───sshd───bash
       └─udevd───2*[udevd]
      
  ```

3. The IPC ways: Pipe;Signal;Message;Semaphore;Socket
