import re, scrapy, sys
sys.path.append("/home/natsu/文档/git/learn/Scrapy_dingdian/Scrapy_dingdian")
from bs4 import BeautifulSoup
from scrapy.http import Request
from items import ScrapyDingdianItem

class Myspider(scrapy.Spider):
    name = 'Scrapy_dingdian'
    allowed_domains = ['23us.us']
    bash_url = 'http://www.23us.us/list/'
    bashurl = '.html'

    def start_requests(self):
        for i in range(1, 11):
            url = self.bash_url + str(i) + '_1' + self.bashurl
            yield Request(url, self.parse)

    def parse(self, response):
        max_num = BeautifulSoup(response.text, 'lxml').find('div', class_='pagelink').find_all('a')[-1].get_text()
        if int(max_num) > 2:
            max_num = '2'
        bashurl = str(response.url)[:-7]
        for num in range(1, int(max_num) + 1):
            url = bashurl + '_' + str(num) + self.bashurl
            yield Request(url, self.get_name)

    def get_name(self, response):
        tds = BeautifulSoup(response.text, 'lxml').find_all('tr', bgcolor='#FFFFFF')
        for td in tds:
            novelname = td.find('a').get_text()
            novelurl = td.find('a')['href']
            yield Request(novelurl, callback = self.get_chapterurl, meta={'name': novelname, 'url': novelurl})

    def get_chapterurl(self, response):
        item = ScrapyDingdianItem()
        item['name'] = str(response.meta['name']).replace('\xa0', '')
        item['novelurl'] = response.meta['url']
        category = BeautifulSoup(response.text, 'lxml').find('table').find('a').get_text()
        author = BeautifulSoup(response.text, 'lxml').find('table').find_all('td')[1].get_text()
        serialstatus = BeautifulSoup(response.text, 'lxml').find('table').find_all('td')[2].get_text()
        serialnumber = BeautifulSoup(response.text, 'lxml').find('table').find_all('td')[4].get_text()
        bash_url = BeautifulSoup(response.text, 'lxml').find('p', class_ = 'btnlinks').find('a', class_ = 'read')['href']
        name_id = str(bash_url)[-6:-1].replace('/', '')
        item['category'] = str(category).replace('/', '')
        item['author'] = str(author).replace('/', '')
        item['serialstatus'] = str(serialstatus).replace('\xa0', '')
        item['serialnumber'] = str(serialnumber).replace('\xa0', '')
        item['name_id'] = name_id
        return item
