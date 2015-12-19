import spam

def TestSystem():
    r = spam.system("ls -l")
    assert r == 0

def TestNothingDone():
    r = spam.nothing_done()
    assert r is None
