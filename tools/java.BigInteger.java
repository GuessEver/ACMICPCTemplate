BigInteger a = BigInteger.valueOf(100);
BigInteger b = BigInteger.valueOf(50);
BigInteger ONE = BigInteger.ONE;
BigInteger TWO = BigInteger.valueOf(2);
a = a.add(ONE).subtract(b);
a = a.multiply(TWO).divide(TWO);
a = a.mod(TWO);
a.compareTo(ONE); // 大于1, 小于-1, 等于0
//BigDecimal 为高精小数
