const axios = require("axios");

async function parse(inputArray) {
  try {
    const response = await axios("https://api.fliplet.com/v1/widgets/assets");
    const { assets = {} } = response.data || {};

    const result = findAllAssetsPaths(assets, inputArray);

    return result;
  } catch (error) {
    console.log("Error:: fetching assets");
    throw error;
  }
}

function findAllAssetsPaths(assets, inputArray) {
  const filteredAsset = Object.keys(assets)
    .filter((asset) => inputArray.some((toParse) => asset === toParse))
    .map((key) => assets[key]);

  const resultToSend = [];
  if (!filteredAsset) return;

  for (const asset of filteredAsset) {
    const minimumVersion = Object.keys(asset.versions).reduce(
      (p, c) => (p > c ? p : c),
      ""
    );

    resultToSend.push(asset.versions[minimumVersion]);

    if (asset.dependencies)
      resultToSend.push(findAllAssetsPaths(assets, asset.dependencies).flat());
  }

  return removeDuplicates(resultToSend.flat());
}

function removeDuplicates(arr) {
  return arr.filter((el, index) => arr.indexOf(el) === index);
}

parse(["bootstrap", "fliplet-core", "moment", "jquery"]).then(function (
  assets
) {
  console.log("The list is", assets);
});
