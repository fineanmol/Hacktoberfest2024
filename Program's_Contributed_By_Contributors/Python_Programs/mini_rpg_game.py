import random
import os

class Hero:

	#private class variabel
	__jumlah = 0

	def __init__(self,name,health,attPower,armor):
		self.__name = name
		self.__healthStandar = health
		self.__attPowerStandar = attPower
		self.__armorStandar = armor
		self.__level = 1
		self.__exp = 0

		self.__healthMax = self.__healthStandar * self.__level
		self.__attPower = self.__attPowerStandar * self.__level
		self.__armor = self.__armorStandar * self.__level

		self.__health = self.__healthMax

		Hero.__jumlah += 1

	@property
	def info(self):
		if self.__health <= 0:
			return "{} level {}: \n\tDEAD".format(self.__name,self.__level)
		else:
			return "{} level {}: \n\thealth = {}/{} \n\tattack = {} \n\tarmor = {}".format(self.__name,self.__level,self.__health,self.__healthMax,self.__attPower,self.__armor)

	@property
	def gainExp(self): # getter
		pass

	@gainExp.setter
	def gainExp(self,addExp): 
		self.__exp += addExp
		if (self.__exp >= 100):
			print(self.__name, 'level up!! Regenerasi sebesar 50%')
			self.__level += 1
			self.__exp -= 100

			self.__healthMax = self.__healthStandar * self.__level
			self.__attPower = self.__attPowerStandar * self.__level
			self.__armor = self.__armorStandar * self.__level
			self.__health =+ int(self.__healthMax * 0.5)



	def counterAttack(self, musuh):
		counterDmg = random.randint(0, int(musuh.__attPower / 2))
		critRate = random.random()
		critDmg = 2
		if critRate <= 0.7:
			counterDmg *= critDmg

		return counterDmg


	def attack(self, musuh):
		counterRate = random.random()
		randomChance = random.random()
		if musuh.__health > 0:
			if counterRate <= randomChance:
				counterDmg = self.counterAttack(musuh)
				print("Berhasil menyerang. Musuh melakukan counter attack sebesar ", counterDmg)
				self.__health -= counterDmg
				musuh.__health -= self.__attPower - musuh.__armor
			else:
				print("Berhasil menyerang dengan telak, regenerasi sebesar 5%")
				musuh.__health -= self.__attPower
				self.__health += int(self.__healthMax * 0.05)
				self.gainExp = 30
		else:
			print("Anda tidak bisa menyerang karena musuh sudah mati")
			return False
	
	def generateEnemy(self):
		name = random.choice(['goblin','ogre','troll','dragon','demon'])
		health = random.randint(100,200)
		attPower = random.randint(10,100)
		armor = random.randint(1,10)
		enemy = Hero(name,health,attPower,armor)
		return enemy


	def groupEnemy(self):
		enemy = []
		for i in range(5):
			enemy.append(self.generateEnemy())
		return enemy
	
	def pickEnemy(self):
		enemy = self.groupEnemy()
		enemy = random.choice(enemy)
		return enemy



if __name__ == '__main__':

	# create hero
	player = Hero('player',100,50,5)
	# select enemy
	enemy = player.pickEnemy()

	# MENU
	while True:
		print("Pilih menu: ")
		print("1. Serang")
		print("2. Lihat status")
		print("3. Clear")
		print("4. Musuh selanjutnya")
		print("5. Keluar")
		menu = int(input("Pilih menu: "))

		if menu == 1:
			player.attack(enemy)
			print(player.info)
			print(enemy.info)
		elif menu == 2:
			print("-"*10 + "Status Anda" + "-"*10)
			print(player.info)
			print("-"*10 + "Status Musuh" + "-"*10)
			print(enemy.info)
		elif menu == 3:
			os.system('cls')
		elif menu == 4:
			enemy = player.pickEnemy()
			print("Musuh Anda sekarang adalah \n", enemy.info)
		elif menu == 5:
			break
		else:
			print("Menu tidak tersedia")