<script>

function getKey(str,key)
{
	
	key=key.split("");
	if(str.length == key.length)
		return key.join("");
	else
	{
		let temp=key.length;
		for (let i = 0;i<(str.length-temp) ; i++)
		{
			
			key.push(key[i % ((key).length)])
		}
	}
	return key.join("");
}


function encrypt(str,key)
{
	let cipher_text="";

	for (let i = 0; i < str.length; i++)
	{
		let x = (str[i].charCodeAt(0) + key[i].charCodeAt(0)) %26;

		x += 'A'.charCodeAt(0);

		cipher_text+=String.fromCharCode(x);
	}
	return cipher_text;
}

function dcrypt(cipher_text,key)
{
	let orig_text="";

	for (let i = 0 ; i < cipher_text.length ; i++)
	{
		let z = (cipher_text[i].charCodeAt(0) -
					key[i].charCodeAt(0) + 26) %26;

		z += 'A'.charCodeAt(0);
		orig_text+=String.fromCharCode(z);
	}
	return orig_text;
}


function LowToUpCase(s)
{
	let str =(s).split("");
	for(let i = 0; i < s.length; i++)
	{
		if(s[i] == s[i].toLowerCase())
		{
			str[i] = s[i].toUpperCase();
		}
	}
	s = str.toString();
	return s;
}

let str = "hello world";
let keyword = "tesla";


let key = getKey(str, keyword);

let cipher_text = encrypt(str, key);

document.write("Encrypted message : "
				+ cipher_text);

document.write("Decrypted message : "
				+ decrypt(cipher_text, key));


</script>
