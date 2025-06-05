let interval
let notification
document.addEventListener('visibilitychange',()=>{
    if(document.visibilityState === 'hidden'){
        const leaveDate = new Date();
        interval = setInterval(()=>{
            notification = new Notification("Come back please",{
                body: `You have been inactive for ${Math.round((new Date() - leaveDate) / 1000)} seconds, come back to continue your work.`,
                tag:"Come Back"
            })
        },100)
    }else{
        if(interval) clearInterval(interval)
        if(notification) notification.close()
    }
})