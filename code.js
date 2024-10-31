var userId = 'sys_id_of_user'; // Replace with the user's sys_id
var gr = new GlideRecord('incident');
gr.addQuery('assigned_to', userId);
gr.query();

while (gr.next()) {
    gs.info('Incident: ' + gr.number + ' - ' + gr.short_description);
}
