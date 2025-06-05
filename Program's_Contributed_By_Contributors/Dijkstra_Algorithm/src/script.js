const container = document.getElementById('network');
const edges = new vis.DataSet();
const nodes = new vis.DataSet();

let network;

document.getElementById('generateBtn').addEventListener('click', generateGraph);
document.getElementById('runDijkstraBtn').addEventListener('click', runDijkstra);

function generateGraph() {
const previousPathLabel = document.querySelector('.shortest-path');
if (previousPathLabel) {
previousPathLabel.remove();
}

const numNodes = parseInt(document.getElementById('numNodes').value);
const isDirected = document.getElementById('directed').checked;

nodes.clear();
edges.clear();

// Create nodes
for (let i = 0; i < numNodes; i++) {
nodes.add({ id: i, label: `Node ${i}`, color: { background: 'lightgray' } });
}

// Create random edges ensuring each node is connected and update edge weights
for (let i = 0; i < numNodes - 1; i++) {
const weight = Math.floor(Math.random() * 10) + 1;
edges.add({ from: i, to: i + 1, label: `${weight}`, weight: weight });
}

// Add random edges to create connections without parallel edges and update weights
const existingEdges = new Map(); // To track existing edges and their weights
for (let i = 0; i < Math.floor(numNodes * 1.5); i++) {
const fromNode = Math.floor(Math.random() * numNodes);
const toNode = Math.floor(Math.random() * numNodes);

// Avoid self-loops
if (fromNode !== toNode) {
    const edgeIdentifier = isDirected ? `${fromNode}->${toNode}` : `${fromNode}-${toNode}`;
    
    if (existingEdges.has(edgeIdentifier)) {
        // Edge already exists, update its weight
        const existingEdge = existingEdges.get(edgeIdentifier);
        const newWeight = Math.floor(Math.random() * 10) + 1; // New random weight
        edges.update({ id: existingEdge.id, label: `${newWeight}`, weight: newWeight });
    } else {
        // Create new edge
        const weight = Math.floor(Math.random() * 10) + 1;
        const edgeId = edges.length + 1; // Simple way to generate a unique id
        edges.add({
            id: edgeId,
            from: fromNode,
            to: toNode,
            label: `${weight}`,
            weight: weight,
            arrows: isDirected ? 'to' : undefined
        });
        existingEdges.set(edgeIdentifier, { id: edgeId, weight }); // Track the edge and its weight
    }
}
}

const data = {
nodes: nodes,
edges: edges,
};

const options = {
physics: true,
edges: {
    smooth: false,
    color: { inherit: false },
},
};

network = new vis.Network(container, data, options);
}


class PriorityQueue {
constructor(compareFn) {
this.items = [];
this.compareFn = compareFn;
}

enqueue(item) {
this.items.push(item);
this.items.sort(this.compareFn);
}

dequeue() {
return this.items.shift();
}

isEmpty() {
return this.items.length === 0;
}
}

function runDijkstra() {
const startNode = 0; // You can change this to let users select the starting node.
const distances = {};
const previous = {};
const queue = new PriorityQueue((a, b) => a[1] < b[1]);

nodes.forEach(node => {
distances[node.id] = Infinity;
previous[node.id] = null;
});

distances[startNode] = 0;
queue.enqueue([startNode, 0]);

while (!queue.isEmpty()) {
const [currentNode, currentDistance] = queue.dequeue();

network.body.data.nodes.update({ id: currentNode, color: { background: 'lightgreen' } });

const neighbors = edges.get({
    filter: (edge) => edge.from === currentNode
});

neighbors.forEach(edge => {
    const neighborId = edge.to;
    const weight = edge.weight;
    const distance = currentDistance + weight;

    if (distance < distances[neighborId]) {
        distances[neighborId] = distance;
        previous[neighborId] = currentNode;
        queue.enqueue([neighborId, distance]);

        network.body.data.nodes.update({ id: neighborId, color: { background: 'lightyellow' } });
        network.body.data.edges.update({ id: edge.id, color: { color: 'blue' } });
    }
});
}

// Animate shortest path highlighting
animateShortestPath(previous, startNode, distances);
}

function animateShortestPath(previous, startNode, distances) {
const endNode = nodes.length - 1; // Change this to the desired end node
const path = [];
const edgeWeights = []; // Array to store edge weights
let totalCost = distances[endNode]; // Get the total cost from distances

// Reconstruct the path from endNode to startNode
for (let at = endNode; at !== null; at = previous[at]) {
path.push(at);
}
path.reverse(); // Reverse to get the correct order

// Collect edge weights along the path
for (let i = 0; i < path.length - 1; i++) {
const edgeWeight = edges.get({
    filter: (edge) => (edge.from === path[i] && edge.to === path[i + 1]) || 
                      (edge.from === path[i + 1] && edge.to === path[i])
})[0].weight; // Get the weight of the edge
edgeWeights.push(edgeWeight);
}

// Highlight the path
let delay = 0;
path.forEach((node, index) => {
setTimeout(() => {
    network.body.data.nodes.update({ id: node, color: { background: 'red' } });

    if (index < path.length - 1) {
        const edgeId = edges.get({
            filter: (edge) => (edge.from === node && edge.to === path[index + 1]) || 
                              (edge.from === path[index + 1] && edge.to === node)
        })[0].id;

        network.body.data.edges.update({ id: edgeId, color: { color: 'red' } });
    }
}, delay);
delay += 1000; // Adjust this value to control the speed of the animation
});

// Display the shortest path, its cost, and edge weights below the graph
const pathLabel = `Shortest path: ${path.join(' -> ')}`;
const costLabel = `Cost of shortest path: ${totalCost}`;
const weightsLabel = `Edge weights: ${edgeWeights.join(', ')}`;

let container = document.createElement('div');
container.className = 'shortest-path';
container.innerHTML = `<div>${pathLabel}</div><div>${costLabel}</div>`;

const previousPathLabel = document.querySelector('.shortest-path');
if (previousPathLabel) {
previousPathLabel.remove();
}
document.querySelector('.container').appendChild(container);
}
