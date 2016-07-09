#include "thread_test.h"
#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
extern MainWindow *w;

void callback(u_char *args, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    char s_mac[50]={0} ;//sprintf s_mac, d_mac
    char d_mac[50]={0} ;
    sprintf(s_mac, "%02x.%02x.%02x.%02x.%02x.%02x",packet[0],packet[1],packet[2],packet[3],packet[4],packet[5]);
    //printf("s_mac :: %s  ",s_mac);
    sprintf(d_mac,"%02x.%02x.%02x.%02x.%02x.%02x",packet[6],packet[7],packet[8],packet[9],packet[10],packet[11]);
    //printf("d_mac :: %s\n",d_mac);




    //eth_type define
    char e_type[20]={0};
    unsigned short eth_type = ntohs(*((unsigned short *)&(packet[12])));
    if (eth_type == 0x800){sprintf(e_type,"IPv4");}
    else if (eth_type == 0x0806){sprintf(e_type,"ARP");}
    else if (eth_type == 0x8035){sprintf(e_type,"RARP");}
    else if (eth_type == 0x8100){sprintf(e_type,"VLAN");}
    else if (eth_type == 0x8847){sprintf(e_type,"MPLS");}
    else if (eth_type == 0x8864){sprintf(e_type,"PPPOE");}
    //printf("e_type :: %s\n",e_type);

    char s_ip[20] = {0};
    char d_ip[20] = {0};
    sprintf(s_ip,"%0d.%0d.%0d.%0d",packet[26],packet[27],packet[28],packet[29]);
    sprintf(d_ip,"%0d.%0d.%0d.%0d",packet[30],packet[31],packet[32],packet[33]);

    //printf("Source_IP  : %03d.%03d.%03d.%03d            ",packet[26],packet[27],packet[28],packet[29]);
    //printf("Destination_IP  : %03d.%03d.%03d.%03d       ",packet[30],packet[31],packet[32],packet[33]);

    char ip_type[10] = {0};
    unsigned short IP_type = (*((unsigned short *)&(packet[23])))&0xFF;

    if (IP_type == 1){sprintf(ip_type,"ICMP");}
    else if (IP_type == 2){sprintf(ip_type,"IGMP");}
    else if (IP_type == 6){sprintf(ip_type,"TCP");}
    else if (IP_type == 17){sprintf(ip_type,"UDP");}
    else if (IP_type == 80){sprintf(ip_type,"ISP-IP");}
    else if (IP_type == 88){sprintf(ip_type,"EIGRP");}
    else {sprintf(ip_type,"Exception");}

    unsigned short src_port = ntohs(*((unsigned short *)&(packet[34])));
    unsigned short des_port = ntohs(*((unsigned short *)&(packet[36])));
    char s_port[10] ={0};
    char d_port[10] ={0};
    sprintf(s_port,"%d",src_port);
    sprintf(d_port,"%d",des_port);

    //printf("s_port : %05d                          ",s_port);
    //printf("d_port : %05d\n",d_port);
    //printf("\n");

    //printf("%d",s_port);




   w->Packet_data(s_mac, d_mac, e_type, s_ip, d_ip, ip_type, s_port, d_port);
};



Thread_test::Thread_test(QObject *parent) :
    QThread(parent)
{
}

void Thread_test::run()
{

            //packet captureint Packet(int argc, char **argv)

                int i;
                    char *dev;
                    char errbuf[PCAP_ERRBUF_SIZE];
                    pcap_t *descr;
                    const u_char *packet;
                    struct pcap_pkthdr hdr;			/* pcap.h */


                    //device select
                   // printf("%X\n",errbuf+2);
                    dev=pcap_lookupdev(errbuf);
                    if(dev == NULL)
                    {
                        printf("%s\n", errbuf);
                        exit(1);
                    }

               //     printf("device : %s\n", dev);

                    //device packet capture descriptor
                    descr = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
                        if (descr == NULL)
                        {
                          //  printf("pcap_open_live(): %s\n", errbuf);
                            exit(1);
                        }

                        //packet capture
                        packet = pcap_next(descr, &hdr);
                        if (packet == NULL)
                        {
                            //printf("Fail_Capture_Packet!\n");
                            exit(1);
                        }

                        pcap_loop(descr, -1, callback, NULL);


        }





