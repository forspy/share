/*
设置VWware硬盘空间100G以上 内存2G 

ubuntu16.04中文设置
右上角设置-区域和语言-具体参见https://blog.csdn.net/qq_19339041/article/details/80058575
程序安装和删除可通过左侧"ubuntu软件管理"
时间和时区设置可在 设置-详细信息-日期和时间里面设置
第一次进入使用管理员权限
sudu su  然后输入密码  #表示root用户

通过管理员权限安装gcc（c）、g++（c++）编译器和vim编辑器
指令为：
sudu apt-get install gcc
sudo apt-get install g++
sudu apt-get install vim-gtk

vi main.c 新建一个vim文档
按i输入 按esc键跳出 ：wq 保存退出  ：q！不保存退出  ：set nu 显示行号
使用gcc main.c 可以看到多了一个a.out  
运行a.out  ./a.out  （./表示当前文件夹  ../表示上一层文件夹）
*/
