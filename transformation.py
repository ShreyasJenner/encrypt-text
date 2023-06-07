flag = ç©æ¯ää»ã¶å½¢æ¥´çæ¥®ç´ã´ææ½¦å¼¸å½¥ã°ã¢ã¸ã½

trans = ''.join([chr((ord(flag[i]) << 8) + ord(flag[i + 1])) for i in range(0, len(flag), 2)])

print(trans)
