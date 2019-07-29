# Deecamp  HD Map Project  

切记！此repo关系到本组全部资料代码内容，在训练营期间请勿外传！

### 项目成员

```
JokerJohn : 胡想成
ustc-keyanjie ：柯延杰
yohoochen : 王友辰
smartfish.liu@gmail.com ：刘欢鲤
jhch1995 : 姜昊辰
joy427 ：陈卓
LiuFG : 刘丰刚
zhangjing1997 ：张景
Danial.Lin : 林中亚
DaHaiHuha ：程大海
0HaNC : 林瀚熙
```

### 文件夹描述

```
自行创建一个以自己姓名命名的文件夹，如hxc
```

### 分工安排（11人）

```
Product Manager：程大海
检测部分（4人）：
	车道线：王友辰、刘欢锂
	地标、交通灯、交通牌：林瀚熙、柯延杰
深度估计（3人）：林中亚、张景、姜昊辰
坐标变换/匹配更新（4人）：姜昊辰、刘丰刚、陈卓、胡想成
存储+可视化（3人）：程大海、胡想成、张景
设计师：吴坷
```

### 技术方案

```
https://shimo.im/docs/gqPgyHg9gpJgQYtR/ 《胡想成组技术方案v1.1》
```

### 克隆项目到本地文件夹

```
https://github.com/JokerJohn/HDMapProject.git
```

### 修改之前先拉取github上的更新

```
git pull
```

### 添加修改后的文件

```
git add 
```

### 修改后添加修改说明

```
git commit -m "..."
```

### 把修改推送到coding的master分支

```
git push origin master
```

### git配置 (ubuntu) (配置过则忽略)
1. 配置名称和电子邮件：
```
git config --global user.name "your_github_account"
git config --global user.email "account_related_email_address"

git config --list #check
```
2. git push/pull免输入账号和密码

2.1 创建文件，进入文件，输入内容：
```
cd ~
touch .git-credentials
vim .git-credentials
https://{username}:{password}@github.com
```
2.2 配置credential
```
git config --global credential.helper store
```
2.3 check，打开~/.gitconfig文件，会发现多了一项:
```
[credential]
    helper = store
```
