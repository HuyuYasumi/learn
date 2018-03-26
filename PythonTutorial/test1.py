import os, time, random, multiprocessing

def write(q):
    print('Process to write: %s' % os.getpid())
    for value in ['A', 'B', 'C']:
        print('Put %s to queue...' % value)
        q.put(value)
        time.sleep(random.random())

def read(q):
    print('Process to read: %s' % os.getpid())
    while True:
        value = q.get(True)
        print('Get %s from queue.' % value)

if __name__ == '__main__':
    print('Parent process %s.' % os.getpid())
    q = multiprocessing.Queue()
    pw = multiprocessing.Process(target = write, args = (q,))
    pr = multiprocessing.Process(target = read, args = (q,))
    pw.start()
    pr.start()
    print('Put Parent desuyo to queue...')
    q.put('Parent desuyo')
    pw.join()
    pr.terminate()
    print(multiprocessing.cpu_count())
