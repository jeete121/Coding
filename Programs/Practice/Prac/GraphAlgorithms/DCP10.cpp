#include <bits/stdc++.h>
using namespace std;


int threadCount = 0

def job():
    id = threadCount
    print()
    print("Job instance #"+str(id)+" started at",datetime.now())
    time.sleep(10)
    print()
    print("Job instance #"+str(id)+" ended at", datetime.now())

def scheduler(f, n):
    global threadCount
    while True:
        t = threading.Thread(target=f)
        t.start()
        time.sleep(n/1000)
        threadCount += 1

if __name__ == "__main__":
    scheduler(job, 5000)