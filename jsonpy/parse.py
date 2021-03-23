
import json, sys

j_file_name = sys.argv[1]
t_file_name = sys.argv[2]

f=open(t_file_name, mode='wt', encoding='utf-8')
with open(j_file_name)as json_file:
    data=json.load(json_file)

    for item in data:
        if("user_profile" in item):
            txt = item["text"]
            prof = item["user_profile"]
            if("display_name" in prof):
                name = prof["display_name"]
            if(len(name)==0):
                name = prof["real_name"]
            f.write(name)
            f.write(': ')
            f.write(txt)
            f.write('\n\n')
