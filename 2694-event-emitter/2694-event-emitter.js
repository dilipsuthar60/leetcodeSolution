class EventEmitter {
    constructor(){
        this.event=new Map();
    }
    subscribe(eventName, callback) {
        if(!this.event.has(eventName)){
            this.event.set(eventName,[]);
        }
        const list = this.event.get(eventName);
        list.push(callback);
        return {
            unsubscribe: () => {
                const index=list.indexOf(callback);
                if(index!==-1){
                    list.splice(index,1);
                }
            }
        };
    }
    emit(eventName, args = []) {
        if(!this.event.has(eventName)) return []
        const subscribe=this.event.get(eventName);
        if(!subscribe) return [];
        const result=[]
        for(let callback of subscribe){
            result.push(callback(...args));
        }
        return result
    }
}