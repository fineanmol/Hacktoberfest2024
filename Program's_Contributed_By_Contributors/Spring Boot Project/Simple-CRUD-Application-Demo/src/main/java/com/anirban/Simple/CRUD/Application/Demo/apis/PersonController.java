package com.anirban.Simple.CRUD.Application.Demo.apis;

import com.anirban.Simple.CRUD.Application.Demo.models.Person;
import com.anirban.Simple.CRUD.Application.Demo.services.PersonService;
import lombok.AllArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.List;
import java.util.Optional;
import java.util.UUID;


@RestController
@AllArgsConstructor
@RequestMapping("api/v1/person")
public class PersonController {
    private PersonService personService;

    @PostMapping
    public void addPerson(@Valid @NonNull @RequestBody Person person) {
        personService.addPerson(person);
    }

    @GetMapping
    public List<Person> getAllPerson() {
        return personService.getAllPersons();
    }

    @GetMapping(path = "{id}")
    public Optional<Person> getPersonById(@PathVariable("id") UUID id) {
        return personService.getPersonById(id);
    }

    @DeleteMapping(path = "{id}")
    public int deletePerson(@PathVariable("id") UUID id) {
        return personService.deletePerson(id);
    }

    @PutMapping("{id}")
    public int updatePerson(@PathVariable("id") UUID id,
                            @Valid @NonNull @RequestBody Person updatedPerson) {
        return personService.updatePerson(id, updatedPerson);
    }
}
