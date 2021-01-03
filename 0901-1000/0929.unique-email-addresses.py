class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        def convert(email):
            name, domain = email.split('@')
            ai = name.find('+')
            if ai != -1:
                name = name[:ai]
            return name.replace('.', '') + '@' + domain
        return len(set(map(convert, emails)))
            

