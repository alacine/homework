#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <network.h>
#define	STGRAN	1	/* Timer granularity (delay) in seconds	*/
/*------------------------------------------------------------------------
 * slowtimer - handle long-term periodic maintenance of network tables
 *------------------------------------------------------------------------
 */
PROCESS	slowtimer()
{
    long	lasttime, now;	/* previous and current times in seconds*/
    //int	delay;	/* actual delay in seconds	*/
    double delay; /*使用double类型, 使得delay的精度更高*/

    signal(Net.sema);
    gettime(&lasttime);
    lasttime_arp = lasttime;
    lasttime_ipf = lasttime;
    lasttime_rt = lasttime;
    lasttime_ospf = lasttime;

    while (1) {
        sleep(STGRAN);
        /* 每一个计时器的delay单独计算 */
        gettime(&now);
        delay = now - lasttime_arp;
        if (delay <= 0 || delay > 4*STGRAN)
            delay = STGRAN;	/* likely clock reset */
        lasttime_arp = now;
        arptimer(delay);

        gettime(&now);
        delay = now - lasttime_ipf;
        if (delay <= 0 || delay > 4*STGRAN)
            delay = STGRAN;	/* likely clock reset */
        lasttime_arp = now;
        ipftimer(delay);

        gettime(&now);
        delay = now - lasttime_rt;
        if (delay <= 0 || delay > 4*STGRAN)
            delay = STGRAN;	/* likely clock reset */
        lasttime_arp = now;
        rttimer(delay);

#ifdef OSPF
        gettime(&now);
        delay = now - lasttime_ospf;
        if (delay <= 0 || delay > 4*STGRAN)
            delay = STGRAN;	/* likely clock reset */
        lasttime_ospf = now;
        ospftimer(delay);
#endif /* OSPF */
    }
}
