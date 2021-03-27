import datetime
import os
from tqdm import tqdm

EXTS = dict([
    ('.cpp', 'C++'),
    ('.py', 'Python'),
    ('.go', 'Go'),
    ('.rs', 'Rust'),
    ('.scala', 'Scala'),
    ('.sh', 'Shell'),
])


class Problem:
    def __init__(self, id, title, acceptance, difficulty):
        self.id = int(id)
        self.title = title.strip()
        self.acceptance = acceptance
        self.difficulty = difficulty
        self.link = self.get_link()
        self.path = ""
        self.solutions = []
    def get_link(self):
        signs = '()'
        prefix = 'https://leetcode-cn.com/problems/'
        link = ''.join([c for c in self.title.lower() if c not in signs])
        link = prefix + link.replace(' ', '-').replace(',', '').replace('`', '')
        return link

def difficulty2level(difficulty):
    c = difficulty[0].lower()
    if c == 'e':
        return 1
    elif c == 'm':
        return 2
    elif c == 'h':
        return 3
    return 0

def read_problems_list(fname):
    problems = {}
    with open(fname) as fin:
        fin.readline() # skip
        while 1:
            pid = fin.readline()
            if not pid:
                break
            pid = int(pid)
            info = fin.readline()
            sp = info.split()
            difficulty = sp[-1]
            acceptance = sp[-2]
            name = ' '.join(sp[:-2])
            problem = Problem(pid, name, acceptance, difficulty)
            problems[pid] = problem
    return problems

def get_problem_id(name):
    try:
        si = name.index('.')
        pid = int(name[:si])
        return pid
    except:
        try:
            si = name.index('-')
            pid = int(name[:si])
            return pid
        except:
            pass
    return None


list_fname = './problems.lst'
PROBLEM_LIST = read_problems_list(list_fname)

def is_solution_dir(dname):
    if not os.path.isdir(dname):
        return False
    if len(dname) != 9:
        return False
    # xxxx-xxxx
    if dname[4] != '-':
        return False
    try:
        return int(dname[:4]) < int(dname[5:])
    except:
        return False

def get_finished_problems():
    global PROBLEM_LIST
    problems = set()
    for dname in os.listdir():
        if is_solution_dir(dname):
            for fname in os.listdir(dname):
                name, ext = os.path.splitext(fname)
                full_name = os.path.join(dname, fname)
                if ext in EXTS:
                    pid = get_problem_id(fname)
                    if pid is not None:
                        code_type = EXTS[ext]
                        problems.add(pid)
                        if pid in PROBLEM_LIST:
                            PROBLEM_LIST[pid].solutions.append((code_type, full_name))
    return problems


FINISHED_PROBLEMS = get_finished_problems()

tqdm.format_interval = lambda days: f'{int(round(days))} days'

def write_all_problems():
    n = len(FINISHED_PROBLEMS)
    total = len(PROBLEM_LIST)
    days = (datetime.date.today() - datetime.date(2019, 1, 15)).days
    elapsed = days
    progress = tqdm.format_meter(n, total, elapsed, ncols=100)

    with open('problems.md', 'w') as fout:
        fout.write("""## Problems

```
{progress}
```

Done|Title|Solution(s)|Difficulty|Topic
-|-|-|-|-
""".format(progress=progress))
        for p in PROBLEM_LIST.values():
            flag = '✔' if p.id in FINISHED_PROBLEMS else '-'

            solutions = ', '.join([
                f'[{code_type}]({os.path.join(p.path, fname)})'
                for code_type, fname in sorted(p.solutions)
            ])
            msg = f'{flag}|[{p.id}.{p.title}]({p.link})|{solutions}|{p.difficulty}|'
            if p.path:
                msg += f'[{p.path}]({p.path})'
            # Add Code
            fout.write(msg + '\n')

if __name__ == '__main__':
    write_all_problems()
