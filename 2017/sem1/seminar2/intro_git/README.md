1. Поговорить о <s>жизни</s> git
  * git - распределённая система версионирования
  * концепция код на сервере / код на локальной машине
  * порисовать линейное дерево (локальное и серверное),
    объяснить, что такое кружочки (дельты), сказать про commit hash (~unique id)
  * какой workflow будет для домашних заданий
  * рассказать, что такое master
  * какой workflow обычно принят и почему (потому что распределённая система)
  * сказать, чтобы записали основные команды и что они делают
2. visit gitlab.com and create the new repo
3. `git clone`
4. show .git content (just that it exists)
5. рассказать про локальную работу репозитория (commited / актуальное состояние / cache-staging for commit)
  * на каждом следующем шаге показывать, чему равны три состояния
6. create README.md with the single line of text
7. create main.cpp with several lines of text
8. `git status`
9. `git diff` (total + per file)
10. `git add` files (show status per each file)
11. `git diff` - show that it is empty
12. `git diff --cached` - show how to see changes in staging
13. `git commit` - create commit
14. add three lines to README.md
15. add something to the main.cpp
16. `git status`
17. `git add README.md` (show git status)
18. `git reset README.md` - how to remove changes from staging
19. `git checkout main.cpp` - (simple way how to lost all changes) - revert state to staging
20. commit changes to README
21. `git push origin master` - send changes to server (show files on server)
22. make another commit to README (delete 1 line, change another, show unchanged server content)
23. show commits tree
  * `git log`
  * `git log --graph`
  * `git log --oneline --decorate --graph`
24. `git push origin master`
25. `git show <commit hash>` - show commit diff
