from html.parser import HTMLParser
from urllib import request

class MyHTMLParser(HTMLParser):
    flag, name, time, location, count = False, False, False, False, False
    fdata = {}
    def handle_starttag(self, tag, attrs):
        if tag == 'ul':
            for attr in attrs:
                if r'list-recent-events menu' in attr[1]:
                    #print([x for x in attrs])
                    self.flag = True
        if self.flag == True and tag == 'a':
            self.count = self.count + 1
            self.name = True
        if self.flag == True and tag == 'time':
            self.time = True
        if self.flag == True and tag == 'span':
            self.location = True

    def handle_data(self, data):
        if self.name == True:
            self.fdata['name%s' % self.count] = data
            self.name = False
        if self.time == True:
            self.fdata['time%s' % self.count] = data
            self.time = False
        if self.location == True:
            self.fdata['location%s' % self.count] = data
            self.location = False

    def handle_endtag(self, tag):
        if self.flag == True and tag == 'ul':
            self.flag = False

    def show_events(self):
        for i in range(1, self.count+1):
            print('Event #%s:' % i)
            if self.fdata['name%s' % i]:
                print('Name:',self.fdata['name%s' % i])
            if self.fdata['time%s' % i]:
                print('Time:', self.fdata['time%s' % i])
            if self.fdata['location%s' % i]:
                print('Location:', self.fdata['location%s' % i], '\n')
        return self.fdata

parser = MyHTMLParser()
with request.urlopen('https://www.python.org/events/python-events/') as f:
    parser.feed(f.read().decode('utf-8'))
parser.show_events()

