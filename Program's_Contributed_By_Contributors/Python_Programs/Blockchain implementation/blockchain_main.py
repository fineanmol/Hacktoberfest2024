# Import libraries
 
import datetime     # for timestamp
import hashlib      # calculating hash
import json         # store amount 
from flask import Flask, jsonify
import requests
from uuid import uuid4
from urllib.parse import urlparse
 
# Building a Blockchain
 
class Blockchain:

    # genesis block 
    def __init__(self):
        self.blocks = []
        self.transactions = []
        self.create_block( proof = 1, prev_hash = '0')
        self.nodes = set()

    def create_block(self, proof, prev_hash):

        """
        Create a new block in the Blockchain
        proof : The proof given by the Proof of Work algorithm
        prev_hash : Hash of prev Block
        return : New Block
        """

        block = {'index': len(self.blocks) + 1,
                 'timestamp': str(datetime.datetime.now()),
                 'proof': proof,
                 'prev_hash': prev_hash,
                 'transactions': self.transactions}
        self.transactions = []
        self.blocks.append(block)
        return block
 
    def get_prev_block(self):
        return self.blocks[-1]
 
    def proof_of_work(self, prev_proof, prev_hash):

        """"
        POW algorithm
        prev_block : prev block (dictionary)
        return : New proof (integer)
        """

        curr_proof = 1
        check_proof = False

        while check_proof is False:

            hash_operation = hashlib.sha256((str(curr_proof) + str(prev_proof) + str(prev_hash)).encode()).hexdigest()

            if hash_operation[:4] == '0000':    # Run iterations till we find a string with leading 4 zeroes 
                check_proof = True
            else:
                curr_proof += 1
        return curr_proof
    
    def hash(self, block):

        """
        Creates a SHA-256 hash of a Block
        block : Block
        return : SHA-256 hash in hexadecimal
        """

        # Dictionary should be ordered to have consistent hashes
        encoded_block = json.dumps(block, sort_keys = True).encode()
        hash_ret = hashlib.sha256(encoded_block).hexdigest()
        return hash_ret
    
    def is_chain_valid(self, blocks):

        """
        Determines if a given blockchain is valid
        blocks : Blockchain
        return: True if valid, False if not
        """

        prev_block = blocks[0]
        block_index = 1
        while block_index < len(blocks):
            block = blocks[block_index]
            if block['prev_hash'] != self.hash(prev_block):     # Check that the hash of the block is correct
                return False

            prev_proof = prev_block['proof']
            proof = block['proof']
            prev_hash = block['prev_hash']

            hash_operation = hashlib.sha256((str(proof) + str(prev_proof) + str(prev_hash)).encode()).hexdigest()

            if hash_operation[:4] != '0000':    # Check that the Proof of Work is correct
                return False
            prev_block = block
            block_index += 1
        return True

    def add_transaction(self, originator, beneficiary, amount):

        """"
        add transactions, as a json format in postman in post request for demo
        originator : sender
        beneficiary : reciever
        """

        self.transactions.append({'originator': originator,
                                  'beneficiary': beneficiary,
                                  'amount': amount})
        previous_block = self.get_previous_block()

        # return the index of the current block (+1 for genesis block)
        return previous_block['index'] + 1

    
    def add_node(self, address):
        parsed_url = urlparse(address)
        self.nodes.add(parsed_url.netloc)

    def replace_chain(self):

        """"
        Replacing the chain with the longest chain,  
        if it has the length greater than the current length update the max_length and the longest chain
        """

        network = self.nodes
        longest_chain = None
        max_length = len(self.chain)
        
        for node in network:
            response = requests.get(f'http://{node}/get_chain')
            # checking for chain validity
            if response.status_code == 200:     
                
                length = response.json()['length']
                chain = response.json()['chain']

                if length > max_length and self.is_chain_valid(chain):
                    max_length = length
                    longest_chain = chain

        if longest_chain:
            self.chain = longest_chain
            return True
        return False
 

# Flask for Web App
app = Flask(__name__)

# Creating an address for the node on the port 5000
# uuid4() creates a random universally unique identifier 
# (UUID - generated using synchronization methods that ensure no two processes can obtain the same UUID)node_address = str(uuid4()).replace('-', '')
node_address = str(uuid4()).replace('-', '')

# Creating a Blockchain object
blockchain = Blockchain()
 
# Mining a new block
@app.route('/mine_block', methods = ['GET'])
def mine_block():
    """
    we need previous block and its proof
    calculate the current proof
    create the current block with that proof and prev hash
    """ 
    prev_block = blockchain.get_prev_block()
    prev_proof = prev_block['proof']
    prev_hash = blockchain.hash(prev_block)
    proof = blockchain.proof_of_work(prev_proof, prev_hash)

    blockchain.add_transaction(originator = node_address, beneficiary = 'Anuradha', amount = 1)
    block = blockchain.create_block(proof, prev_hash)
    response = {'message': 'Block has been mined!',
                'index': block['index'],
                'timestamp': block['timestamp'],
                'proof': block['proof'],
                'prev_hash': block['prev_hash'],
                'transactions': block['transactions']}
    return jsonify(response), 200
 
# Getting the whole Blockchain
@app.route('/get_chain', methods = ['GET'])
def get_chain():
    response = {'blocks': blockchain.blocks,
                'length': len(blockchain.blocks)}
    return jsonify(response), 200
 
# Checking for Blockchain validity
@app.route('/is_valid', methods = ['GET'])
def is_valid():
    is_valid = blockchain.is_chain_valid(blockchain.blocks)
    if is_valid:
        response = {'message': 'The Blockchain is valid.'}
    else:
        response = {'message': 'The Blockchain is not valid.'}
    return jsonify(response), 200


# Decentralizing the blockchain

# Connects new nodes
@app.route('/connect_node', methods = ['POST'])
def connect_node():
    json = requests.get_json()
    nodes = json.get('nodes')
    
    # return none if node feild is null
    if nodes is None:
        return 'No node', 400
    
    for node in nodes:
        blockchain.add_node(node)

    # give the response for all the connected nodes and display the nodes
    response = {'message' : 'All the nodes are now connected.',
                'total_nodes' : list(blockchain.nodes)}
    
    # http 201 - request has succeeded and has led to the creation of a resource
    return jsonify(response), 201

# Replacing the chain by the longest chain
@app.route('/replace_chain', methods = ['GET'])
def replace_chain():

    # If any chain is larger then we will replace the chain by the longest chain or else display the same chain
    is_chain_replaced = blockchain.replace_chain()
    if is_chain_replaced:
        response = {'message': 'The nodes are different so the chain is replaced by the longest chain.',
                    'new_chain' : blockchain.chain}
    else:
        response = {'message': 'The current chain is the largest one',
                    'new_chain' : blockchain.chain}
    return jsonify(response), 200
 
# Running the app
app.run(host = '0.0.0.0', port = 5000)