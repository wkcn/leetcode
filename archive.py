import os

for fname in os.listdir('.'):
    name, ext = os.path.splitext(fname)
    if ext in ['.cpp', '.py', '.rs', '.scala', '.sh', '.go']:
        for c in ['.', '-']:
            if c in name:
                fi = name.find(c)
                if fi == -1:
                    continue
                try:
                    tid = int(name[:fi])
                except Exception:
                    continue
                tname = name[fi + 1:]
                print(tid, tname)
                new_name = '%.4d%s%s' % (tid, c, tname) + ext
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
                break
