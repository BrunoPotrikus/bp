function cadastraPessoa () {
	const container = document.querySelector('.container');
	const inputName = document.querySelector('.nome');
	const inputLastName = document.querySelector('.sobrenome');
	const inputBthDay = document.querySelector('.dt-nascimento');
	const inputPhone = document.querySelector('.fone');
	const inputEmail = document.querySelector('.email');

	class Pessoa {
		constructor (nome, sobrenome, dtNascimento, fone, email) {
			this.nome = nome;
			this.sobrenome = sobrenome;
			this.dtNascimento = dtNascimento;
			this.fone = fone;
			this.email = email;
		}
		
	}

	function createDiv () {
		const div = document.createElement('div');
		return div;
	}

	function createP () {
		const p = document.createElement('p');
		return p;
	}

	function addPerson (name, lastname, bthDay, phone, email) {
		const pessoa = new Pessoa(name, lastname, bthDay, phone, email);
		const div = createDiv();
		const p = CreateP();
		console.log(pessoa);	
		p.appendChild(pessoa.nome);
		div.appendChild(p);
		container.appendChild(div);
	} 	
	
	document.addEventListener('click', function (event) {
		const e = event.target;
		
		if (e.classList.contains('btn-cadastro')) {
			if (!inputName.value ||
			!inputLastName.value ||
			!inputBthDay.value ||
			!inputPhone.value ||
			!inputEmail.value) return 'Preencha todos os campos';
			
			addPerson(inputName.value,
				inputLastName.value,
				inputBthDay.value,
				inputPhone,
				inputEmail);
	
		}
	});
}
cadastraPessoa();