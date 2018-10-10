const hacktoberCache = 'v1';
const cacheFiles = [
	'./',
    './index.html',
    './contributors.html',
    './helpful-material.html',
    './css/contributors.css',
    './css/footer.css',
    './css/helpful-material.css',
    './css/index.css',
    './css/navbar.css',
];

// install the service worker
self.addEventListener('install', (event) => {
	event.waitUntil(
		caches.open(hacktoberCache).then((cache) => {
			console.log('SW Cache is installing');
			return cache.addAll(cacheFiles);
		}).then((skip) => {
			console.log('Service Worker Skip waiting');
			self.skipWaiting();
			console.log('Service Worker properly installed');
			return skip;
		}).catch((error) => {
			console.log('SW Open & Cache install failed with ' + error);
		})
	);
});

// activate service worker
self.addEventListener('activate', (event) => {
	event.waitUntil(
		caches.keys().then((hacktoberCaches) => {
			return Promise.all(hacktoberCaches.map((cache) => {
				//if cache versions to not match, delete old version
				if (cache !== hacktoberCache) {
					return caches.delete(cache);
				}
			}));
		})
	);
});

// fetch service worker
self.addEventListener('fetch', (event) => {
	let request = event.request;
	event.respondWith (
			fetch(request).then(
				(response) => {
					//check valid response basic means we do NOT cache 3rd party responses
					if(!response || response.status !== 200 || response.type !== 'basic') {
						return response;
					}
					let responseToCache = response.clone();

					caches.open(hacktoberCache)
						.then((cache) => {
							cache.put(request, responseToCache);
						});
					return response;
				}
			).catch((err) => {
				caches.match(request).then((response) => {
					if (response) {
						return response;
					}
				})
			})
	);
});