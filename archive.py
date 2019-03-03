import os

for fname in os.listdir('.'):
    name, ext = os.path.splitext(fname)
    if ext in ['.cpp']:
        if '.' in name:
            sp = name.split('.')
            try:
                tid = int(sp[0])
            except Exception:
                continue
            tname = sp[1]
            print(tid, tname)
            new_name = '%.4d.%s' % (tid, tname) + ext
            # 1: 1 - 100
            # 2: 101 - 200
            page = (tid - 1) // 100 + 1
            page_start = (page - 1) * 100 + 1
            page_end = page * 100
            page_name = '%.4d-%.4d' % (page_start, page_end)
            if not os.path.exists(page_name):
                os.mkdir(page_name)
            new_path = os.path.join(page_name, new_name)
            os.system('mv %s %s' % (fname, new_path))
            os.system('git rm %s --cached' % fname)
            os.system('git add %s' % new_path)
