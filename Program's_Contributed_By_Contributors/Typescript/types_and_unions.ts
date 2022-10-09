type ID = string
type PopularTag = string
type MaybePopularTag = PopularTag | null

interface UserInterface {
	id :ID
	name: string,
	surname: string
}

const popularTags: PopularTag[] = ["dragon", "coffee"]

const dragonTag: MaybePopularTag = "dragon"

let username: string = "alex"
let pageNumber: string | number = "1"
let errorMessage: string | null = null //common usecase, when requesting for a resource that isnt yet present
let user: UserInterface | null = null

let someProp : string | number | null | undefined | string[] | object = 0 //bad code, do not write like this

