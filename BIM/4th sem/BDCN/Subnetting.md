## 1. Suppose an ISP owns the block of addresses of the form 200.201.202.0 and it wants to create six subnets from this block, with each block having the same number of IP addresses. Calculate subnet mask, range, netid, broadcast id and prefixes (of form a.b.c.d/x) for the six subnets.


| Subnet | Network ID     | Usable Range                     | Broadcast ID     | Prefix |
|--------|----------------|----------------------------------|------------------|--------|
| 1      | 200.201.202.0  | 200.201.202.1 - 200.201.202.30   | 200.201.202.31   | /27    |
| 2      | 200.201.202.32 | 200.201.202.33 - 200.201.202.62  | 200.201.202.63   | /27    |
| 3      | 200.201.202.64 | 200.201.202.65 - 200.201.202.94  | 200.201.202.95   | /27    |
| 4      | 200.201.202.96 | 200.201.202.97 - 200.201.202.126 | 200.201.202.127  | /27    |
| 5      | 200.201.202.128| 200.201.202.129 - 200.201.202.158| 200.201.202.159  | /27    |
| 6      | 200.201.202.160| 200.201.202.161 - 200.201.202.190| 200.201.202.191  | /27    |

✔ Subnet Mask: 255.255.255.224 (/27).
✔ Hosts per Subnet: 30 usable IPs.
✔ Total Subnets Created: 8 (but only 6 used).
✔ Broadcast ID = Last IP in the subnet.
✔ Network ID = First IP in the subnet.

## 2. Suppose an ISP owns the block of addresses of the form 210.249.240.0 and it wants to create Six subnets from this block, with each block having the same number of IP addresses. Calculate subnet mask, usable IP range, network id and broadcast id in each subnet.

| Subnet | Network ID      | Usable IP Range                  | Broadcast ID    | Prefix           |
|--------|-----------------|----------------------------------|-----------------|------------------|
| 1      | 210.249.240.0   | 210.249.240.1 - 210.249.240.30   | 210.249.240.31  | 210.249.240.0/27 |
| 2      | 210.249.240.32  | 210.249.240.33 - 210.249.240.62  | 210.249.240.63  | 210.249.240.32/27 |
| 3      | 210.249.240.64  | 210.249.240.65 - 210.249.240.94  | 210.249.240.95  | 210.249.240.64/27 |
| 4      | 210.249.240.96  | 210.249.240.97 - 210.249.240.126 | 210.249.240.127 | 210.249.240.96/27 |
| 5      | 210.249.240.128 | 210.249.240.129 - 210.249.240.158| 210.249.240.159 | 210.249.240.128/27 |
| 6      | 210.249.240.160 | 210.249.240.161 - 210.249.240.190| 210.249.240.191 | 210.249.240.160/27 |

