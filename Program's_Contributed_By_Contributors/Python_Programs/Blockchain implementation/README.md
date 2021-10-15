# Blockchain-implementation

## Files present
6 files are present in the zip file -
1. blockchain.py: file that consists of the Blockchain class and Application of Flask
2. blockchain_5001.py: a copy of blockchain.py on the 5001 port
3. blockchain_5002.py: a copy of blockchain.py on the 5002 port
4. blockchain_5003.py: a copy of blockchain.py on the 5003 port
5. nodes.json: addresses of nodes
6. transaction.json: originator, beneficiary, and amount

## Requirements
1. Python 3.x
2. Flask
3. Requests
4. Postman

## Functionalities of Blockchain

1. User has information regarding all the available blocks. The **get_chain** function returns the information (index, previous hash, proof, timestamp, transactions) about all the blocks in the chain.

![i1](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i1.png)
![i2](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i2.png)
![i3](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i3.png)

2. Unverified user shouldn't be able to edit the added transactions. The **proof_of_work** and **is_chain_valid** help in the verification and authentication of the blockchain.

![i4](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i4.png)
![i5](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i5.png)

3. Timestamp of each transaction is readily available. The datetime library in Python was used, and the timestamp is a part of every block in the blockchain.

![i6](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i6.png)

4. User should have all the information regarding the completed transactions.
- Run the three files - blockchain_5001, blockchain_5002, blockchain_5003 separately to three nodes in your local machine.
- Connect these nodes using the POST request in postman.

![i7](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i7.png)
![i8](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i8.png)
![i9](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i9.png)

- Adding transactions : Transaction can be added as a post method in postman. We can then mine the block using **mine_block** to increase the length of the blockchain (can be seen in the **get_chain** picture)

![i10](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i10.png)
![i11](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i11.png)

Updating the nodes :

- Since it is a distributed system if one blocks mines and updates the chain all other nodes should update their chain.
- We will replace the chain with the longest valid chain using **replace_chain** by checking all other nodes, otherwise we will not update

![i12](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i12.png)
![i13](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i13.png)

Adding transactions :
Transaction from Anuradha -> Vamsi using add_transaction

![i14](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i14.png)

**get_chain** displays the updates of the transacted amount

![i15](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i15.png)

Use **replace_chain** and **get_chain** in other methods to get the updated blockchain.

![i16](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i16.png)
![i17](https://github.com/pandeyanuradha/Blockchain-implementation/blob/main/Project%20implementation%20images/i17.png)
