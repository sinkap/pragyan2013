setwd("~/pragyan2013/Demos/staticModel/")
x = scan("network.log")
x = x / 1024
set.seed(2)
library("PerformanceAnalytics")
x = Return.clean(x, method = "boudt")
x = diff(x,1)

library("rugarch")
z = matrix(rnorm(666*30), ncol = 30)
kp = ugarchspec(mean.model = list(armaOrder = c(2,1,0), arfima = TRUE), variance.model = list(garchOrder = c(1, 
    1), model = "sGARCH"))
a = ugarchfit(spec = kp,data = x, solver.control=list(trace = 1))
f = ts(fitted(a))
d = ts(x)
res = a@fit$residuals[0:2]
rets = x[0:2]
sig = a@fit$sigma[0:2]
#plot(diffinv(f,1))
#lines(diffinv(d,1))


#plot(d)
#lines(f, col = "blue")

foo = ugarchsim(a, n.sim = 666, m.sim = 30,startMethod = "sample", n.start = 0, presigma = sig, preresiduals = res, prereturns = rets) 
plot(ts(as.data.frame(foo, which = "series")[1]),col = "red")
lines(ts(x), col = "blue")

plot(foo)
