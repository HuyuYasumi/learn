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
        if self.flag:
            if tag == 'a':
                self.count = self.count + 1
                self.name = True
            elif tag == 'time':
                self.time = True
            elif tag == 'span':
                self.location = True

    def handle_data(self, data):
        if data:
            if self.name:
                self.fdata['name%s' % self.count] = data
                self.name = False
            if self.time:
                self.fdata['time%s' % self.count] = data
                self.time = False
            if self.location:
                self.fdata['location%s' % self.count] = data
                self.location = False
        else:
            if self.name:
                self.fdata['name%s' % self.count] = none
                self.name = False
            if self.time:
                self.fdata['time%s' % self.count] = none
                self.time = False
            if self.location:
                self.fdata['location%s' % self.count] = none
                self.location = False

    def handle_endtag(self, tag):
        if self.flag and tag == 'ul':
            self.flag = False

    def show_events(self):
        for i in range(1, self.count+1):
            print('Event #%s:' % i)
            print('Name:',self.fdata['name%s' % i])
            print('Time:', self.fdata['time%s' % i])
            print('Location:', self.fdata['location%s' % i], '\n')
        return self.fdata

parser = MyHTMLParser()
with request.urlopen('https://www.python.org/events/python-events/', timeout=4) as f:
    parser.feed(f.read().decode('utf-8'))
parser.show_events()

