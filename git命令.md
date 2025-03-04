# 1.配置和初始化仓库

## 1.1 git init
    'git init'初始化一个Git仓库
    
```
# [] 表示其中的内容可以省略
# 可以初始化某个指定目录
git init [<directory>]
```

## 1.2 git config
    'git config'配置用户名和邮箱，具体格式如下：
```
git config --global user.name "user.name"
git config --global user.email "user.email@example.com"
```

    其中'--global'表示，用了该参数，这台机器上所有的Git仓库都会使用这个配置；可以对某个仓库指定不同的用户名和Email地址
    Git 配置信息存储在三个不同的层级：系统级（system）、用户级（global）和仓库级（local）
    之后可以通过下列命令来查看配置信息

```
# 查看所有配置信息
git config --list
git config -l

# 查看系统级配置信息
git config --system --list

# 查看用户级（全局）配置信息
git config --global --list

# 查看仓库级配置信息
git config --local --list
```

## 1.3 git clone
    使用'git clone'命令可以从Git拷贝项目
```
# url为git仓库地址，directory为本地目录，可指定或不指定
git clone <url> [directory]
```

# 2.基本操作 

## 2.1 git status
    使用'git status'命令可以查看当前目录的状态
```
# 显示信息：
# 当前分支名称
# 当前分支与远程分支的关系
# 未暂存的修改：显示已修改但尚未使用 'git add' 添加到暂存区的文件列表
# 未跟踪的文件：显示尚未纳入版本控制的新文件列表
git status
```
    常用选项：

```
# 获得简短的输出结果
git status -s
git status --short

# 显示分支和跟踪信息
git status -b
git status -branch

# 显示未跟踪的文件
git status -u
git status --untracked-files

# 显示变更的文件内容
git status -v
git status --verbose
```
## 2.2 git diff
    执行'git diff'来查看更新的详细信息，与'git status'不同的是'git diff'可以显示以写入缓存和已修改但尚未写入缓存的改动的区别的具体信息

```
# 尚未缓存的改动 
git diff

# 查看已缓存的改动
git diff --cached

# 查看已缓存的和未缓存的所有改动
git diff HEAD

# 显示摘要而非整个diff
git diff --stat
```

## 2.3 git add
    要想让文件成为Git仓库的管理对象，就需要用'git add'将其加入到暂存区。暂存区是提交之前的一个临时区域

```
git add filename

# 添加所有文件
git add .

# 指定某一类文件
git add *.java
```

## 2.4 git commit
    'git commit'将缓存内容添加到本地仓库中

```
# '-m' 用于在命令行中添加提交信息，注释
git commit -m "提交信息"

# 也可以只提交暂存区内的某些文件
git commit [file1] [file2] -m "提交信息"

# 不想每次都使用'git add',可以使用 '-a'直接提交所有已跟踪的文件
git commit -am "提交信息"

# 发现提交信息有误，或者需要补充一些修改，这时可以使用 '--amend'选项：
git commit --amend -m "新的提交信息"

# 多行提交信息
git commit -m "标题" -m "详细描述"
```
## 2.5 git reset
    Git必须知道当前版本是哪个版本，在Git中，用HEAD表示当前版本，上一个版本就是HEAD^，上上一个版本就是HEAD^^，以此类推；
    也可以使用～数字表示HEAD~0 表示当前版本，HEAD~1 上一个版本，HEAD~2表示上上一个版本，HEAD~3表示上上上一个版本，以此类推
    'git reset'的作用是修改HEAD的位置，即将HEAD指向的位置改变为之前存在的某个版本

```
# '--hard'：移动本地库HEAD指针，重置缓存区，重置工作区
# --hard 撤销工作区中所有未提交的修改内容，将暂存区与工作区都回到上一次版本，并删除之前的所有信息提交。换句话说，就是你的没有commit的修改会被全部擦掉。

# 回退到上一版本
git reset --hard HEAD^

#回退到指定版本号（以1a2b3c为例）的版本：
git reset --hard 1a2b3c


# '--soft'：移动本地库HEAD指针，重置缓存区
# --soft 则会保留工作目录的内容，并把因为重置 HEAD 所带来的新的文件差异放进暂存区

# 回退上上上一个版本 
git reset --soft HEAD~3  


# '--mixed'：默认，可以不用带该参数，用于重置暂存区的文件与上一次的提交(commit)保持一致，工作区文件内容保持不变。

# 用于取消已缓存的内容
git reset HEAD <filename>
git reset --mixed HEAD <filename>
```
## 2.6 git rm
    'git rm' 用于删除文件
    如果只是手动在工作目录中删除文件，运行'git status'就会出现 'Changes not staged for commit' 的提示

```
# 仅删除工作区
rm <filename>

# 将文件从暂存区和工作区删除
git rm <filename>

# 如果删除之前修改过并且已经放到暂存区域的话，则必须要用强制删除选项 -f
git rm -f <filename>

# 将文件从暂存区移除，工作区保留
git rm --cached <filename>
```
## 2.7 git mv
    'git mv'用于移动或重命名一个文件、目录。并在Git索引中记录该变更
```
# 重命名,在git视角该操作既是重命名也是移动操作
git mv <oldfilename> <newfilename>

# 移动文件
git mv <源文件路径> <目的文件路径>

# 如果该文件已存在，可以使用强制执行 -f / --force
git mv -f <源文件路径> <目的文件路径>
```

## 2.8 git show
    'git show'用于显示Git对象的详细信息

```
# 基本语法
# <options> 显示的选项和格式
# <object> 指定的Git对象，可以是提交哈希、标签、分支名等
git show [<options>] [<object>]

# 显示提交的详细信息
git show [<object>]

# 显示提交的差异(补丁)
git show --patch [<object>]

# 显示提交的文件列表，只显示文件名
git show --name-only [<object>]

# 显示提交的统计信息，包括更改的文件和行数
git show --stat [<object>]

# 使用 --pretty=format: 自定义提交信息的输出格式
git show --pretty=format:"%h - %an, %ar : %s" [<object>]

# 显示标签的详细信息
git show <tag>
```
## 2.9 git tag
    如果你达到一个重要的阶段，并希望永远记住提交的快照，你可以使用 git tag 给它打上标签
    'git tag'用于给仓库中的特定提交点加上标记

```
# 标准格式
git tag <tagname>

# -a 可以添加注释
# 执行'git tag -a'命令时，Git 会打开你的编辑器，让你写一句标签注解，就像你给提交写注解一样
git tag -a <tagname>

# -m 指定附注信息
git tag -a <tagname> -m "附注信息"

# 删除指定名称的标签
git tag -d <tagname>
```

# 3.查看提交历史

## 3.1 git log
    'git log'一般用于在使用 Git 提交了若干更新之后，又或者克隆了某个项目，想回顾下提交历史，我们可以使用 git log 命令查看
    显示了从最新提交到最早提交的所有提交信息，包括提交的哈希值、作者、提交日期和提交消息等

```
# 基本语法
git log [<选项>] [<分支名/提交哈希>]

# 用 --oneline 选项来查看历史记录的简洁的版本
git log --oneline

# 用 --graph 选项，查看历史中什么时候出现了分支、合并。以下为相同的命令，开启了拓扑图选项
git log --graph 

# --reverse 来逆向显示所有日志
git log --reverse

# --author 用于查找指定用户提交日志
git log --author="user.name" 

# 限制显示的提交数,例如显示最近的5次提交
git log -n 5

# 显示自指定日期之后的提交
git log --since="2025-02-28"
git log --after="2025-02-28"

# 显示自指定日期之前的提交
git log --until="2025-02-28"
git log --before="2025-02-28"
```
## 3.2 git blame
    'git blame'用于逐行显示指定文件的每一行代码是由谁在什么时候引入或修改的
    可以追踪文件中每一行的变更历史，包括作者、提交哈希、提交日期和提交消息等信息

```
# 标准格式
git blame [选项] <文件路径>

# 只显示指定行号范围内的代码注释
git blame -L <起始行号>,<结束行号> <文件路径>

# 对于重命名或拷贝的代码行，也进行代码行溯源
git blame -C <文件路径>

# 对于移动的代码行，也进行代码行溯源
git blame -M <文件路径>

# 显示行数统计信息
git blame --show-stats <文件路径>
```

## 3.3 git shortlog
    'git shortlog'主要用于总结 Git 仓库的提交历史，提供对每位作者的提交计数以及每个提交类别的概览


``` 
# 标准格式
# <revision-range>：指定要生成摘要的提交范围，默认为当前分支的全部提交
git shortlog [选项] [<revision-range>]

# 按提交数量对作者进行排序，显示每个作者的提交数量
git shortlog -n
git shortlog --numbered

# 仅显示作者及其提交数量，不显示提交信息
git shortlog -s
git shortlog --summary

# 显示作者及其电子邮件地址
git shortlog -e
git shortlog --email

# 按提交者（committer）统计提交数量，而不是作者（author）
git shortlog -c
git shortlog --committer

# 排除合并提交，仅显示非合并提交的摘要
git shortlog --no-merges

# 仅显示指定时间范围内的提交摘要
git shortlog --since="2023-01-01" --until="2023-06-30"

# 自定义输出格式，以显示提交哈希和提交信息
git shortlog --pretty=format:"%h %s"
```

# 4.分支管理

## 4.1 git branch
    'git branch'用于查看和创建分支，具体操作如下

```
# 查看本地分支
git branch
# 查看远程分支
git branch -r
# 查看本地和远程分支
git branch -a

# 创建分支
git branch <分支名>
# 删除分支
git branch -d <分支名>
```
## 4.2 git checkout
    'git checkout'用于切换到指定的分支或恢复工作目录中的文件。也可以用来检出特定的提交
```
# 切换分支
git checkout <branch_name>
# 切换到前一个分支
git checkout -

# 创建并切换到新分支
git checkout -b <branch_name>

# 将工作区指定文件 <file> 恢复到最近一次提交时的状态，丢弃所有未提交的更改
# 放弃某个文件的修改
git checkout -- <filename>

# 强制切换分支并丢弃更改
git checkout -f <branch_name>
```
## 4.3 git merge
    'git merge'用于合并指定分支的更改到当前分支
```
# 将指定分支的更改合并到当前分支
git merge <branch-name>
```
## 4.4 git stash
    'git stash'用于临时保存当前工作目录的更改，以便你可以切换到其他分支或处理其他任务

```
# 保存当前工作进度
git stash

# 查看存储的进度
git stash list

# 应用最近一次存储的进度
git stash apply

# 应用并删除最近一次存储的进度
git stash pop

# 删除指定的stash,具体哪条信息可以用 list查看
git stash drop stash@{n}

# 清空所有存储
git stash clear
```

# 5.远程仓库

## 5.1 git remote
    'git remote'用于管理Git仓库的远程仓库，提供了查看、添加、重命名、删除远程仓库的功能

```
# 列出当前仓库中已配置的远程仓库
git remote

# 列出当前仓库中已配置的远程仓库，并显示它们的 URL
git remote -v

# 添加一个新的远程仓库,指定一个远程仓库的名称和 URL，将其添加到当前仓库中
git remote add <remote_name> <remote_url>

# 将已配置的远程仓库重命名
git remote rename <old_name> <new_name>

# 从当前仓库中删除指定的远程仓库
git remote remove <remote_name>

# 修改指定远程仓库的 URL
git remote set-url <remote_name> <new_url>

# 显示指定远程仓库的详细信息，包括 URL 和跟踪分支
git remote show <remote_name>
```
## 5.2 git fetch
    'git fetch'用于从远程获取代码库
    与'git pull'不同在于当你想要从远端仓库获取最新的状态，然后对变更被合入到本地仓库之前对变更做预览
    为了将获取的变更应用到本地分支，你还需要手动执行'git merge'或者'git rebase'
```
# 这条命令将从名为 origin 的远程仓库中获取所有分支的更新，并存储在本地 
git fetch origin
```

## 5.3 git pull
    'git pull' 其实就是'git fetch'和'git merge'的简写，先从远程仓库获取最新的提交记录，然后将这些提交记录合并到你当前的分支中
```
# 标准格式
git pull [<远程仓库名>] [<远程分支名>:[<本地分支名>..]]

# 将远程主机的某个分支的更新取回，并与本地指定的分支合并
git pull <远程主机名> <远程分支名>:<本地分支名>
# 取回origin主机的next分支，与本地的master合并
git pull origin next:master

# 如果远程分支要与当前分支合并，则省略冒号后面的部分
git pull origin next

# 如果当前分支和远程分支存在追踪关系，可以省略远程分支名
git pull origin

# 如果当前分支只有一个追踪分支，则主机名也可以省略
git pull
```
## 5.4 git push
    'git push' 命令用于从将本地的分支版本上传到远程并合并

```
# 标准格式
git push <远程主机名> <本地分支名>:<远程分支名>

# 如果本地分支名与远程分支名相同，则可以省略冒号
# 将本地的 master 分支推送到 origin 主机的 master 分支
git push origin master
git push origin master：master

# 如果本地版本与远程版本有差异，但又要强制推送可以使用 --force 参数
git push --force origin master
```

## 5.5 git rebase
    变基
    'git rebase'命令用于将一个分支上的更改移到另一个分支之上。它可以帮助保持提交历史的线性，减少合并时的冲突


```
# 标准格式
git rebase <branchname>
```
    rebase的具体操作理解：
    首先构造两个分支master和feature,其中feature在提交点B拉出的分支，master有一个新的提交M，feature有两个新的提交C、D
![](./images/1.png)

    当切换到feature分支，执行了'git rebase master'命令，相当于把先在M分支checkout出了C，再在C上进行开发到D，feature指向D
    这样的操作就是变基，feature是基于master分支的B拉出来的，feature的基底是B。现在master在B之后有了新的提交，就相当于用master上新的提交来作为feature分支的新基底。
    实际操作就是把B之后的feature的提交暂存，然后删除原来的提交，再找到master的最新的提交位置，把存下来的提交再接上去（这个过程就是逐个和新基底处理冲突的过程）
![](./images/2.png)

```
# git pull --rebase = git fetch + git rebase
# git pull = git fetch + git merge
git pull --rebase
```
# 6.补充

## 6.1 Git 文件状态
    Git 的文件状态分为三种：工作目录（Working Directory）、暂存区（Staging Area）、本地仓库（Local Repository） 

### 6.1.1 工作目录（Working Directory）
    工作目录是你在本地计算机上看到的项目文件。它是你实际操作文件的地方，包括查看、编辑、删除和创建文件。所有对文件的更改首先发生在工作目录中。
在工作目录中的文件可能有以下几种状态：
* **未跟踪（Untracked）**：新创建的文件，未被 Git 记录。
* **已修改（Modified）**：已被 Git 跟踪的文件发生了更改，但这些更改还没有被提交到 Git 记录中

### 6.1.2 暂存区（Staging Area）
    暂存区，也称为索引（Index），是一个临时存储区域，用于保存即将提交到本地仓库的更改。你可以选择性地将工作目录中的更改添加到暂存区中，这样你可以一次提交多个文件的更改，而不必提交所有文件的更改。
* 使用 git add <filename> 命令将文件从工作目录添加到暂存区。

### 6.1.3 本地仓库（Local Repository）
    本地仓库是一个隐藏在 .git 目录中的数据库，用于存储项目的所有提交历史记录。每次你提交更改时，Git 会将暂存区中的内容保存到本地仓库中
* 使用 git commit -m "commit message" 命令将暂存区中的更改提交到本地仓库。

## 6.2 文件状态的转换流程

### 6.2.1 未跟踪（Untracked）
    新创建的文件最初是未跟踪的。它们存在于工作目录中，但没有被 Git 跟踪

### 6.2.2 已跟踪（Tracked）
    通过 git add 命令将未跟踪的文件添加到暂存区后，文件变为已跟踪状态

### 6.2.3 已修改（Modified）
    对已跟踪的文件进行更改后，这些更改会显示为已修改状态，但这些更改还未添加到暂存区

### 6.2.4 已暂存（Staged）
    使用 git add 命令将修改过的文件添加到暂存区后，文件进入已暂存状态，等待提交

### 6.2.5 已提交（Committed）
    使用 git commit 命令将暂存区的更改提交到本地仓库后，这些更改被记录下来，文件状态返回为已跟踪状态
