import json

f = open('scons.config', 'w')

data = {
        'gmock_path': '/Users/jiaoew/thirdparty/googlemock-read-only/',
        'log4cplus_path': '/Users/jiaoew/thirdparty/log4cplus-1.1.2/include/'
    }
json.dump(data,f, indent=4)
f.close()
