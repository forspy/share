/*
设置VWware硬盘空间100G以上 内存2G 
查看-自动调整大小-自动适应客户机

ubuntu16.04中文设置
右上角设置-区域和语言-具体参见https://blog.csdn.net/qq_19339041/article/details/80058575
程序安装和删除可通过左侧"ubuntu软件管理"
时间和时区设置可在 设置-详细信息-日期和时间里面设置
第一次进入使用管理员权限
sudu su  然后输入密码  #表示root用户

通过管理员权限安装gcc（c）、g++（c++）编译器和vim编辑器
指令为：
sudo apt-get install gcc
sudo apt-get install g++
sudo apt-get install vim-gtk

虚拟机 sata0:1找不到 是因为主机没有光驱  需要把光驱中的启动时连接勾掉
如果ubuntu不能自适应窗口需要安装VMware tools 
注意需要把VMware tools 光盘拷出只读文件夹tar （或者）解压 运行 ./vmware-install.pl  如果需要以管理员身份运行可以输入 sudo ./vmware-install.pl
或者先sudu su
然后./vmware-install.pl
*/
/*
linux常用命令：
在Ubuntu中打开终端的快捷键是Ctrl+Alt+T
ubuntu 复制黏贴 ctrl+shift+c ctrl+shift+v
rm -rf 文件夹名称    删除所有文件和子文件夹
mkdir 文件名  如果想建立有空格的文件名需要'a b'

vi main.c 新建一个vim文档
按i输入 按esc键跳出 ：wq 保存退出  ：q！不保存退出  ：set nu 显示行号
使用gcc main.c 可以看到多了一个a.out
运行a.out  ./a.out  （./表示当前文件夹  ../表示上一层文件夹）


解压：
tar -xvf file.tar //解压 tar包

tar -xzvf file.tar.gz //解压tar.gz

tar -xjvf file.tar.bz2   //解压 tar.bz2

tar -xZvf file.tar.Z   //解压tar.Z

unrar e file.rar //解压rar

unzip file.zip //解压zip
*/
