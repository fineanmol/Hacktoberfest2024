import datetime     
import hashlib      
import json        
from flask import Flask,jsonify,request
import requests
from uuid import uuid4
from urllib.parse import urlparse
  
class Blockchain:

    def __init__(self):
        self.blocks = []
        self.transactions = []
        self.create_block(amount = "Genesis", proof = 1, prev_hash = '0')
        self.nodes = set()

    def create_block(self, amount, proof, prev_hash):

        """
        Create a new block in the Blockchain
        amount : Data of the block
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

            if hash_operation[:4] == '0000':    
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
            if block['prev_hash'] != self.hash(prev_block):     
                return False

            prev_proof = prev_block['proof']
            proof = block['proof']
            prev_hash = block['prev_hash']

            hash_operation = hashlib.sha256((str(proof) + str(prev_proof) + str(prev_hash)).encode()).hexdigest()

            if hash_operation[:4] != '0000':    
                return False
            prev_block = block
            block_index += 1
        return True

    def add_transaction(self, originator, beneficiary, amount):
        self.transactions.append({'originator': originator,
                                  'beneficiary': beneficiary,
                                  'amount': amount})
        prev_block = self.get_prev_block()
        return prev_block['index'] + 1

    def add_node(self,address):
        parsed_url = urlparse(address)
        self.nodes.add(parsed_url.netloc)

    def replace_chain(self):

        network = self.nodes
        longest_chain = None
        max_length = len(self.blocks)

        for node in network:
            response = requests.get(f'http://{node}/get_chain')
            if response.status_code == 200:

                length = response.json()['length']
                blocks = response.json()['blocks']

                if length > max_length and self.is_chain_valid(blocks):
                    max_length = length
                    longest_chain = blocks

        if longest_chain:
            self.blocks = longest_chain
            return True
        return False
 

app = Flask(__name__)

node_address = str(uuid4()).replace('-', '')

blockchain = Blockchain()
 
@app.route('/mine_block', methods = ['GET'])
def mine_block():
    """
    we need prev block and its proof
    calculate the current proof
    create the current block with that proof and prev hash
    """ 
    prev_block = blockchain.get_prev_block()
    prev_proof = prev_block['proof']
    prev_hash = blockchain.hash(prev_block)
    proof = blockchain.proof_of_work(prev_proof, prev_hash)

    blockchain.add_transaction(originator = node_address, beneficiary = 'Vamsi', amount = 1)
    block = blockchain.create_block(1, proof, prev_hash)
    response = {'message': 'Block has been mined!',
                'index': block['index'],
                'timestamp': block['timestamp'],
                'proof': block['proof'],
                'prev_hash': block['prev_hash'],
                'transactions': block['transactions']}
    return jsonify(response), 200
 
@app.route('/get_chain', methods = ['GET'])
def get_chain():
    response = {'blocks': blockchain.blocks,
                'length': len(blockchain.blocks)}
    return jsonify(response), 200
 
@app.route('/is_valid', methods = ['GET'])
def is_valid():
    is_valid = blockchain.is_chain_valid(blockchain.blocks)
    if is_valid:
        response = {'message': 'The Blockchain is valid.'}
    else:
        response = {'message': 'The Blockchain is not valid.'}
    return jsonify(response), 200

@app.route('/add_transaction', methods = ['POST'])
def add_transaction():
    json = request.get_json()
    transaction_keys = ['originator', 'beneficiary', 'amount']
    if not all(key in json for key in transaction_keys):
        return 'Some elements of the transaction are missing', 400
    index = blockchain.add_transaction(json['originator'], json['beneficiary'], json['amount'])
    response = {'message': f'This transaction will be added to Block {index}'}
    return jsonify(response), 201

@app.route('/connect_node', methods = ['POST'])
def connect_node():

    json = request.get_json()
    nodes = json.get('nodes')

    if nodes is None:
        return 'No node', 400

    for node in nodes:
        blockchain.add_node(node)

    response = {'message' : 'All the nodes are now connected.',
                'total_nodes' : list(blockchain.nodes)}

    return jsonify(response), 201

@app.route('/replace_chain', methods = ['GET'])
def replace_chain():

    is_chain_replaced = blockchain.replace_chain()
    if is_chain_replaced:
        response = {'message': 'The nodes are different so the chain is replaced by the longest chain.',
                    'new_chain' : blockchain.blocks}
    else:
        response = {'message': 'The current chain is the largest one.',
                    'new_chain' : blockchain.blocks}
    return jsonify(response), 200
 
app.run(host = '0.0.0.0', port = 5003)