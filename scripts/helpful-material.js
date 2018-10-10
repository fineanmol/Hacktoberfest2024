//Sort by difficulty number 1 easy, 2 hard...
function sortProject(containerClassName, projectClassName) {
    var items = $(containerClassName);

    items.sort(function(a, b){
        return + $(a).data('difficulty') - + $(b).data('difficulty');
    });

    items.appendTo(projectClassName);
}

sortProject('li>.projectItem', 'li>.otherProjects');
sortProject('li>.easyProjectItem', 'li>.beginnerProjects');

console.log('Script Triggered')
