# 实现 a5/1 加密算法和 rc4 加密算法
import random


def print_name(func):
    """输出函数名称"""
    def wrapper(*args):
        print("{}:".format(func.__name__))
        return func(*args)
    return wrapper


class A51:
    def __init__(self, key_len = 0, x = [], y = [], z = []):
        """
        初始化
        允许自定义x, y, z寄存器中的值(自定义时长度必须符合要求),
        否则随机生成
        """
        self.x = x if len(x) == 19 else [random.randint(0, 1) for i in range(19)]
        self.y = y if len(y) == 19 else [random.randint(0, 1) for i in range(22)]
        self.z = z if len(z) == 19 else [random.randint(0, 1) for i in range(23)]
        self.key_len = key_len
        self.key_stream = self._get_key_stream()

    def _get_key_stream(self) -> str:
        """生成密钥流"""
        key_a51 = []
        for i in range(self.key_len):
            m = 1 if self.x[8] + self.y[10] + self.z[10] > 1 else 0
            if self.x[8] == m:
                xtmp = self.x[13] ^ self.x[16] ^ self.x[17] ^ self.x[18]
                self.x.pop()
                self.x.insert(0, xtmp)
            if self.y[10] == m:
                ytmp = self.y[20] ^ self.y[21]
                self.y.pop()
                self.y.insert(0, ytmp)
            if self.z[10] == m:
                ztmp = self.z[7] ^ self.z[20] ^ self.z[21] ^ self.z[22]
                self.z.pop()
                self.z.insert(0, ztmp)
            key_a51.append(self.x[18] ^ self.y[21] ^ self.z[22])
        return ''.join(map(str, key_a51))

    def crypt(self, text: str) -> str:
        """加密/解密"""
        tmp_text = []
        for i in range(self.key_len):
            tmp_text.append(int(self.key_stream[i]) ^ ord(text[i]))
        new_text = ''.join(map(chr, tmp_text))
        return new_text


class Rc4:
    def __init__(self, key_len):
        """
        初始化;
        接收参数密钥的长度, 随机生成密钥(每一位均为 0~255)
        """
        self.key = [random.randint(0, 255) for i in range(key_len)]
        self.s = [i for i in range(256)]
        self.k = [self.key[i % key_len] for i in range(256)]
        j = 0
        for i in range(256):
            j = (j + self.s[i] + self.k[i]) % 256
            self.s[i], self.s[j] = self.s[j], self.s[i]
        self.key_stream = self._get_key_stream()

    def _get_key_stream(self) -> list:
        """生成密钥流"""
        key_stream = []
        i = j = 0
        for i in range(len(self.key)):
            i = (i + 1) % 256
            j = (j + self.s[i]) % 256
            self.s[i], self.s[j] = self.s[j], self.s[i]
            t = (self.s[i] + self.s[j]) % 256
            key_stream.append(self.s[t])
        return key_stream
    
    def crypt(self, text: str) -> str:
        """加密/解密"""
        new_text = []
        for i in range(len(self.key)):
            new_text.append(self.key_stream[i] ^ ord(text[i]))
        return ''.join(map(chr, new_text))
        

@print_name
def test_a51():
    test_text = "Fire in the hole!" # 明文
    a51 = A51(len(test_text))
    print("明文:", test_text)
    print("密钥流:", a51.key_stream) # 密钥流
    print("密文:", a51.crypt(test_text)) # 加密
    print("密文解密:", a51.crypt(a51.crypt(test_text))) # 解密


@print_name
def test_rc4():
    test_text = "Fire in the hole!" # 明文
    rc4 = Rc4(len(test_text))
    print("明文:", test_text)
    print("密文:", rc4.crypt(test_text)) # 加密
    print("密钥流:", rc4.key_stream) # 密钥流
    print("密文解密:", rc4.crypt(rc4.crypt(test_text))) # 解密


def main():
    test_a51()
    test_rc4()


if __name__ == "__main__":
    main()
