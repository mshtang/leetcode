#coding=utf-8
# 本题为考试多行输入输出规范示例，无需提交，不计分。
import sys
if __name__ == "__main__":
    # 读取第一行的n
    n = int(sys.stdin.readline().strip())
    m = int(sys.stdin.readline().strip())
    ans = 0
    content = {}
    for i in range(n):
        # 读取每一行
        line = sys.stdin.readline().strip()
        content[str(line[0])] = int(line[1])
    if m==0:
        content = sorted(content.items(), key=lambda d:d[0], reverse=True)
    else:
        content = sorted(content.items(), key=lambda d:d[0])

    print(content)
