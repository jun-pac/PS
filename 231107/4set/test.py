#!/bin/python3

from queue import PriorityQueue

class instrument:
    def __init__(self, ID):
        self.ID = ID # Instrument ID
        self.cnt=0
        self.buy = PriorityQueue()
        self.sell = PriorityQueue()
        self.cur_price = -1
    def is_worst(self):
        if(self.cur_price==-1 or (self.buy.qsize==0 and self.sell.qsize==0)):
            return "NO BAD TRADES"
        worst_deal=[0,0,0] # loss, cnt, trade_ID
        if(not self.buy.empty()):
            buymx=self.buy.get()
            worst_price=-buymx[0]
            if(worst_price-self.cur_price>worst_deal[0]):
                worst_deal[0]=worst_price-self.cur_price
                worst_deal[1]=buymx[1]
                worst_deal[2]=buymx[2]
            self.buy.put(buymx)
        if(not self.sell.empty()):
            sellmn=self.sell.get()
            worst_price=sellmn[0]
            if((self.cur_price-worst_price)>worst_deal[0] or ((self.cur_price-worst_price)==worst_deal[0] and sellmn[1]<worst_deal[1])):
                worst_deal[0]=self.cur_price-worst_price
                worst_deal[1]=sellmn[1]
                worst_deal[2]=sellmn[2]
            self.sell.put(sellmn)
        if(worst_deal[0]==0):
            return "NO BAD TRADES"
        else:
            return worst_deal[2]   

class PnLCalculator:
    def __init__(self):
        self.dic={} # instrument_ID, instrument_class

    def process_trade(self, trade_id, instrument_id, buy_sell, price, volume):
        if not instrument_id in self.dic:
            self.dic[instrument_id] = instrument(instrument_id)
        if(buy_sell[0]=='B'):
            self.dic[instrument_id].cnt+=1
            cnt=self.dic[instrument_id].cnt
            self.dic[instrument_id].buy.put((-price,-cnt,trade_id))
        elif(buy_sell[0]=='S'):
            self.dic[instrument_id].cnt+=1
            cnt=self.dic[instrument_id].cnt
            self.dic[instrument_id].sell.put((price,-cnt,trade_id))

    def process_price_update(self, instrument_id, price):
        if not instrument_id in self.dic:
            self.dic[instrument_id] = instrument(instrument_id)
        self.dic[instrument_id].cur_price=price

    def output_worst_trade(self, instrument_id):
        if not instrument_id in self.dic:
            return "NO BAD TRADES"
        return self.dic[instrument_id].is_worst()

if __name__ == "__main__":
    import sys

    calculator = PnLCalculator()
    line = sys.stdin.readline().split()
    n = int(line[0])
    for _ in range(n):
        line = sys.stdin.readline().split()
        if line[0] == "TRADE":
            tradeId = int(line[1])
            instrumentId = line[2]
            buySell = line[3]
            price = int(line[4])
            volume = int(line[5])
            calculator.process_trade(tradeId, instrumentId, buySell, price, volume)
        elif line[0] == "PRICE":
            instrumentId = line[1]
            price = int(line[2])
            calculator.process_price_update(instrumentId, price)
        elif line[0] == "WORST_TRADE":
            instrumentId = line[1]
            print(calculator.output_worst_trade(instrumentId))
        else:
            raise Exception("Malformed input!")
