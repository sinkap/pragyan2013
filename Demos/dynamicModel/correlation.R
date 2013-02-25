kpACF <- function(x) {
	
	xseries = x
	T = length(x)
	lag.max = as.integer(10*log10(T))
	acfx 	= acf(xseries, lag.max = lag.max, plot = FALSE)
	clim0	= qnorm((1 + 0.95)/2)/sqrt(acfx$n.used)
	ylim 	= range(c(-clim0, clim0, as.numeric(acfx$acf)[-1]))
	clx 	= vector(mode = "character", length = lag.max)
	clx[which(as.numeric(acfx$acf)[-1]>=0)] = "steelblue"
	clx[which(as.numeric(acfx$acf)[-1]<0)] = "orange"
	barplot(height = as.numeric(acfx$acf)[-1], names.arg = as.numeric(acfx$lag)[-1], ylim = 1.2*ylim, col = clx,
			ylab = "ACF", xlab="lag", main = "ACF of Observations", cex.main = 0.8)
	abline(h = c(clim0, -clim0), col = "tomato1", lty = 2)
	abline(h = 0, col = "black", lty = 1)
	box()
	grid()

}

kpPACF <- function(x) {
	xseries = x
	T = length(x)
	lag.max = as.integer(10*log10(T))
	acfx 	= acf(xseries^2, lag.max = lag.max, plot = FALSE)
	clim0	= qnorm((1 + 0.95)/2)/sqrt(acfx$n.used)
	ylim 	= range(c(-clim0, clim0, as.numeric(acfx$acf)[-1]))
	clx 	= vector(mode="character",length=lag.max)
	clx[which(as.numeric(acfx$acf)[-1]>=0)] = "steelblue"
	clx[which(as.numeric(acfx$acf)[-1]<0)] = "orange"
	barplot(height = as.numeric(acfx$acf)[-1], names.arg = as.numeric(acfx$lag)[-1], ylim = 1.2*ylim, col = clx,
			ylab = "ACF", xlab="lag", main = "ACF of Squared Observations", cex.main = 0.8)
	abline(h = c(clim0, -clim0), col = "tomato1", lty = 2)
	abline(h = 0, col = "black", lty = 1)
	box()
	grid()

}
