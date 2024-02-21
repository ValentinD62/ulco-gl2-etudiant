import myfibo
if __name__ == '__main__':

    for i in range(11):
        print (f"fibo_naive({i}) = {myfibo.fibo_naive(i)}")
    print("")

    for i in range(11):
        print (f"fibo_iterative({i}) = {myfibo.fibo_iterative(i)}")
