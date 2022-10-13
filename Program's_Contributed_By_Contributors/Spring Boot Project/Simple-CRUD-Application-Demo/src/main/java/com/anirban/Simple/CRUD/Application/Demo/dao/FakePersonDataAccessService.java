package com.anirban.Simple.CRUD.Application.Demo.dao;


import com.anirban.Simple.CRUD.Application.Demo.models.Person;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Repository("fakeDao")

public class FakePersonDataAccessService implements PersonDao {
    private static List<Person> DB = new ArrayList<>();
    @Override
    public int insertPerson(UUID id, Person person) {
        DB.add(new Person(id, person.getName()));
        return 1;
    }

    @Override
    public List<Person> selectAllPerson() {
        return DB;
    }

    @Override
    public Optional<Person> selectPersonById(UUID id) {
        return DB.stream().filter(person -> person.getId().equals(id)).findFirst();
    }

    @Override
    public int deletePersonById(UUID id) {
        Optional<Person> personToDelete = selectPersonById(id);
        if(personToDelete.isEmpty())
            return 0;

        DB.remove(personToDelete.get());
        return 1;
    }

    @Override
    public int updatePersonById(UUID id, Person updatedPerson) {
        return selectPersonById(id).
                map(personToUpdate -> {
                    int indexOfPersonToUpdate = DB.indexOf(personToUpdate);
                    if(indexOfPersonToUpdate >= 0){
                        DB.set(indexOfPersonToUpdate, new Person(id, updatedPerson.getName()));
                        return 1;
                    }
                    return 0;
                }).orElse(0);
    }
}
