from random import randint

for j in range(0,100):
    n = randint(1,30)
    file = open("test_cases/test_case_"+str(j)+".txt","w")
    arr = ['R','P','S']
    print(n,file=file)
    for i in range(n):
        print(arr[randint(0,2)],randint(1,n),randint(1,n),randint(1,n),file=file)